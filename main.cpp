//
// main.cpp 
// Conway's Game of Life with edge wrapping, 
// programmable birth and survival rules
// for Type 1 and Type 2 cells
//
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

// Global declarations
const int RMAX = 10;		// Maximum number of rows in grid
const int CMAX = 10;		// Maximum number of columns in grid
const int MAXAGE = 8;		// Maximum number of generations any cell can survive 
const string BARS = "==========================================================";

// Function prototypes
void OpenInputFile(string filename, ifstream& inFile);
void LoadConstraints(ifstream& inFile, int& num, string& bstring, string& sstring);
void LoadGrid(ifstream& inFile, int grid[][CMAX]);
void PrintGrid(int grid[][CMAX]);
void ComputeNextGrid(int current[][CMAX], int next[][CMAX], int birth[], int survival[]);
void CopyGrid(const int source[][CMAX], int destination[][CMAX]);
int  CountType1Neighbors(int grid[][CMAX], int row, int col);
int  CountType2Neighbors(int grid[][CMAX], int row, int col);
void ParseRequirementsString(string requirements, int reqs[]);

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
}  // End PrintGrid()


void OpenInputFile(string filename, ifstream& inFile){
      inFile.open(filename);
      if (!inFile){
        cerr << "Unable to open file." << filename << endl;
        exit(1);
      }
}


void LoadConstraints(ifstream& inFile, int& num, string& bstring, string& sstring) {
    string header;
    getline(inFile, header); // Skip the header line

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
/***********************************************************************/
/***********************************************************************/

/***********************************************************************/
/***********************************************************************/



