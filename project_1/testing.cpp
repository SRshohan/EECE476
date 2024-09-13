#include <iostream>
#include <fstream>
#include <string>
#include <sstream>


using namespace std;

// Global declarations
const int RMAX = 10;		// Maximum number of rows in grid
const int CMAX = 10;		// Maximum number of columns in grid
const int MAXAGE = 8;		// Maximum number of generations any cell can survive 
const string BARS = "==========================================================";

void LoadConstraints(ifstream& inFile, int& num, string& bstring, string& sstring) {
    string header;
    getline(inFile, header); // Skip the Comment line

    while (getline(inFile, header) && header.empty()){

    }

    num = stoi(header);

    while (getline(inFile, header) && header.empty()){

    }
    bstring = header;

    while (getline(inFile, header) && header.empty()){

    }
    sstring = header;
}

void OpenInputFile(string filename, ifstream& inFile){
    inFile.open(filename);
    if (!inFile) {
        cerr << "Unable to open file: " << filename << endl;
        exit(1);
    }
}




void LoadGrid(ifstream& inFile, int grid[][CMAX]){
    string  line;
    int row = 0;

    while (getline(inFile, line))
    {
        if (line.empty() || !isdigit(line[0])){
            continue;
        }
        if (row >= RMAX){
            cerr << "Error More rows" << endl;
            exit(1);
        }

        istringstream lineStream(line);
        int col =0;
        int value;

        while (lineStream >> value){
            
            if (col >= CMAX){
            cerr << "Error More cols" << endl;
            exit(1);
            }

            grid[row][col] = value;
            col++;
        }
        row++;
    }
}


void CopyGrid(const int source[][CMAX], int destination[][CMAX]){
    for (int i=0; i < RMAX; i++){
        for (int j=0; j < CMAX; j++){
            destination[i][j] = source[i][j];
        }
    }
}


void ParseRequirementsString(string requirements, int reqs[]){
    int length =requirements.size();
    int value;

    for (int i=1; i < length; i++){
        value = requirements[i] - '0';
        if (value > 0 && value<=8){
            reqs[value] = 1;
        }
    }
}


int  CountType1Neighbors(int grid[][CMAX], int row, int col){
    int count = 0;

   
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            
            if (dr == 0 && dc == 0) continue;

            int r = row + dr;
            int c = col + dc;

            
            if (r < 0) r = RMAX - 1;
            if (r >= RMAX) r = 0;
            if (c < 0) c = CMAX - 1;
            if (c >= CMAX) c = 0;

            
            if (grid[r][c] == 1) {
                count++;
            }
        }
    }

    return count;

}

int  CountType2Neighbors(int grid[][CMAX], int row, int col){
    int count = 0;

    // Check and count Type1 neighbors (assuming Type1 is represented by 1)
    for (int dr = -1; dr <= 1; ++dr) {
        for (int dc = -1; dc <= 1; ++dc) {
            // Skip the center cell
            if (dr == 0 && dc == 0) continue;

            int r = row + dr;
            int c = col + dc;

            // Handle wrapping around the grid
            if (r < 0) r = RMAX - 1;
            if (r >= RMAX) r = 0;
            if (c < 0) c = CMAX - 1;
            if (c >= CMAX) c = 0;

            // Count Type1 neighbors
            if (grid[r][c] == 2) {
                count++;
            }
        }
    }

    return count;

}

void ComputeNextGrid(int current[][CMAX], int next[][CMAX], int birth[], int survival[]) {
    for (int row = 0; row < RMAX; row++) {
        for (int col = 0; col < CMAX; col++) {
            int type1Neighbors = CountType1Neighbors(current, row, col);
            int type2Neighbors = CountType2Neighbors(current, row, col);

            int currentState = current[row][col];

            if (currentState == 1) { // Type1 
                if (survival[type1Neighbors] == 1) {
                    next[row][col] = 1; // Survives
                } else {
                    next[row][col] = 0; // Dies
                }
            } else if (currentState == 2) { // Type2 
                if (survival[type2Neighbors] == 1) {
                    next[row][col] = 2; // Survives
                } else {
                    next[row][col] = 0; // Dies
                }
            } else { // Dead cell
                if (birth[type1Neighbors] == 1 && type1Neighbors > type2Neighbors) {
                    next[row][col] = 1; // Type1 born
                } else if (birth[type2Neighbors] == 1 && type2Neighbors > type1Neighbors) {
                    next[row][col] = 2; // Type2 born
                } else {
                    next[row][col] = 0; // No birth
                }
            }
        }
    }
}



void PrintGrid(int grid[][CMAX])
// Outputs grid in desired format
{
  for(int r = 0; r < RMAX; r++)
  {
    for(int c = 0; c < CMAX; c++)
    {
      switch (grid[r][c])
      {
        case 0:  cout << ' ' << '-';   break;

        default:  cout << ' ' << grid[r][c]; break;
      }
    }
    cout << endl;
  }
} 




int main(int argc, char* argv[])
{

  ifstream  inFile;                    // Input stream for reading grid file
  string    filename;				           // Name of grid file
  string    bstring;                   // Birth requirements as C++ string
  string    sstring;                   // Survival requirement as C++ string
  int       currentgrid[RMAX][CMAX];   // Current cell grid
  int       nextgrid[RMAX][CMAX];      // Next cell grid
  int       num;                       // Number of iterations
  int       birth[9], survival[9];     // Birth and survival look up arrays


  if (argc != 2)
  {
    cout << "Usage:  project01  <gridfile>" << endl;
    return 0;
  }
  else
    filename = argv[1];
	
  OpenInputFile(filename, inFile);     // Attempt to open grid file
  if (!inFile)
  {
    cout << "\nError: unable to open '" << filename << "' for input\nTerminating now...\n";
    return 0;
  }
  else
  {
    cout << "\nFile '" << filename << "' opened for input..." << endl;
  }

	
  LoadConstraints(inFile, num, bstring, sstring);  // Load number of iterations, birth and survival strings

  cout << "\nIterations = " << num << endl;
	
  // Exit if birth or survival requirements not specified, otherwise parse birth and survival strings
  if ((bstring[0] != 'B') || (sstring[0] != 'S'))
  {
    cout << "Error: incorrect file formatting" << endl;
    return 0; 
  }
  else	
  {
    // Initialize birth and survival requirements to zero
    for(int k=0; k<9; k++)
    {
      birth[k] = 0;
      survival[k] = 0;
    }			 
    
	// Convert bstring and sstring representations into birth and survival look up tables
    ParseRequirementsString(bstring, birth);
    ParseRequirementsString(sstring, survival);

	cout << "\nSimulation Birth/Survival Configuration\n";
    for(int k=0; k<9; k++)
    {
      cout << "birth[" << k << "] = " << birth[k] << "      survival[" 
           << k << "] = " << survival[k] << "\n";  
	}			 
  }

  	
  LoadGrid(inFile, currentgrid);              // Populate grid
  cout << "\nGrid loaded from file.\n\n";      

  cout << BARS << endl;
  cout << "Iteration = 0" << endl << endl;
  PrintGrid(currentgrid);
  cout << BARS << endl;

  for(int iteration = 1; iteration <= num; iteration++)
  {
    ComputeNextGrid(currentgrid, nextgrid, birth, survival);
    CopyGrid(nextgrid, currentgrid);
    cout << BARS << endl;
    cout << "Iteration = " << iteration << endl << endl;
    PrintGrid(currentgrid);
    cout << BARS << endl;
  } // End iterations loop

  return 0;                            // Done!!
}  // End main()


