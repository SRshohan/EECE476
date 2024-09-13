# Project Report

## Introduction and Problem Statement

The goal of this project is to simulate a cellular automaton model, where different types of cells (Type1 and Type2) interact according to specific birth and survival rules. The simulation is designed to replicate the behavior of these cells on a 2D grid over a set number of iterations, capturing the evolution of the grid at each step.

The problem focuses on configuring a dynamic simulation where cells are born, survive, or die based on their neighbors. The goal is to implement this simulation and track its evolution using well-defined rules and to ensure that the simulation is reproducible.

## Methodology

To solve the problem, the following steps were implemented:

1. Grid Setup: A grid of size RMAX x CMAX is initialized to represent the simulation environment. The initial grid is loaded from an input file using the LoadGrid function, which parses each line of the file and populates the grid.

2. Rules Configuration: The rules for birth and survival are represented by arrays where each index corresponds to the number of neighbors, and the value (0 or 1) at that index determines if the cell survives or is born.

3. Simulation Loop: The simulation runs for a fixed number of iterations, as defined by the user. For each iteration, the grid is updated based on the neighbor counts:
- Type1 and Type2 cells are checked for survival according to their specific neighbor counts.
- Dead cells are checked for potential births based on the surrounding cells.

4. Functions:
- ComputeNextGrid: This function calculates the next state of the grid by applying the birth and survival rules for each cell based on its current state and neighbors.
- CountType1Neighbors and CountType2Neighbors: These helper functions are used to count the number of Type1 and Type2 neighbors around a cell.

5. Execution:
- The program is compiled using clang++ and executed with an input file containing the initial grid configuration. Each iteration prints the grid status to show the evolution.

## Results and Discussions
The simulation results in a dynamic evolution of cells based on the provided rules. For each iteration, the grid's state is printed, showing which cells survive, die, or are born.

- Iteration 0: Shows the initial grid loaded from the input file.
- Iteration 1 - To rest: Demonstrates how some cells survive and new cells are born according to the rules, while others die.

![Output Example Configuration File](/project_1/config_file_input.png)

![Output 1 example](/project_1/output1.png)

![Output 2 Example](/project_1/Output2.png)



The project successfully simulates the behavior of the cellular automaton, with the grid evolving correctly based on the birth and survival configurations. The results highlight the importance of initial configurations and how small changes in neighbor counts can lead to significant differences in the grid's evolution.

## Conclusion

This project helped in understanding the fundamentals of cellular automaton models and how they can be simulated using basic programming techniques. Key learnings include:

- Implementing neighbor-checking logic efficiently.
Understanding how to simulate dynamic systems based on pre-defined rules.
- Developing a robust solution that can handle varying grid sizes and complex rule sets.


### To Run using clang++ compiler
```sh
clang++ main.cpp -o main
```

### To run the complied file
```sh
./main <filename>
```

### Video Link: 
[Youtube](https://youtu.be/0yG1CJw3EMI)