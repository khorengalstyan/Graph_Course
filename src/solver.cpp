#include <fstream>
#include <iostream>

#include "../include/inputSize.hpp"
#include "../include/printText.hpp"
#include "../include/printAscii.hpp"
#include "../include/printGraph.hpp"
#include "../include/coverage.hpp"
#include "../include/matrixes.hpp"
#include "../include/solver.hpp"

void solver()
{
	printSolution();
	size_t rows,cols;
	rows = cols = 0;	
	rows = inputSize(rows, "rows","printSolution");
    cols = inputSize(cols, "cols","printSolution");
    size_t edge = (rows + 1) * cols + (cols + 1) * rows;
    size_t matrixSize = (rows + 1) * (cols + 1);
	std::vector<std::vector<char>> grid(matrixSize, std::vector<char>(matrixSize));
    getAdjacencyMatrix(grid, cols, rows);
    char isMade = grid[0][1];
	system("clear");
    if (isMade == '1' && matrixSize < 53)
    {
        printAdjacencyMatrix(grid, rows, cols);
    }
	
    printGraph(rows, cols);
    std::ofstream myFile("data/coverage.txt", std::ofstream::out | std::ofstream::trunc);

    if (edge % 3 == 0 && edge != 0)
    {
        threeLenghtSimpleChainCoverage(rows, cols);
        printCoverage(rows, cols);
    }	
    else 
    {
		printNoCoverage(rows, cols);	
	}
}



