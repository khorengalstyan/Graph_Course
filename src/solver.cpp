#include <fstream>
#include <iostream>

#include "../include/inputSize.hpp"
#include "../include/printAscii.hpp"
#include "../include/printGraph.hpp"
#include "../include/coverage.hpp"
#include "../include/matrixes.hpp"
#include "../include/solver.hpp"

void solver()
{
	printSolution();
	int rows,cols;
	rows = cols = 0;	
	rows = inputSize(rows,"rows");
    cols = inputSize(cols,"cols");
    size_t edge = (rows + 1) * cols + (cols + 1) * rows;
    unsigned int matrix_size = (rows + 1) * (cols + 1);
    char **grid = new char*[matrix_size];

    for (size_t i = 0; i < matrix_size; ++i)
    {
        grid[i] = new  char[matrix_size];
    }
    getAdjacencyMatrix(grid, cols, rows);
    char isMade = grid[0][1];
    if (isMade == '1' && matrix_size < 53)
    {
        printAdjacencyMatrix(grid, rows, cols);
    }
    printGraph(rows, cols);
    std::ofstream myFile("data/coverage.txt", std::ofstream::out | std::ofstream::trunc);

    if (edge % 3 == 0 && edge != 0)
    {
        threeLenghtSimpleChainCoverage(rows, cols);
        printCoverage(rows, cols);
        for (size_t i = 0; i < matrix_size; ++i)
        {
            delete []grid[i];
        }
        delete []grid;
    }	
    else if (edge % 3 != 0)
    {
		std::cout<<"\033[1;35mGRAPH HAS " << edge << " EDGES\n";
		std::cout<<"\033[1;31mNO COVERAGE\033[0m\n";
		myFile << "GRAPH HAS NO COVERAGE";
	}
	else if (edge == 0)
	{
		system("clear");
		std::cout<<"\033[1;31mGRAPH HAS NO EDGES AND CAN'T BE COVERED\033[0m\n";
		myFile << "GRAPH HAS NO EDGES AND CAN'T BE COVERED\n";
	}
	for (size_t i = 0; i < matrix_size; ++i)
	{
		delete []grid[i];
	}
	delete []grid;
}



