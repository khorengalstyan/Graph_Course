#include <fstream>
#include <iostream>

#include "../include/input_size.hpp"
#include "../include/print_graph.hpp"
#include "../include/coverage.hpp"
#include "../include/matrixes.hpp"

void solver()
{	
	int rows,cols;
	rows = cols = 0;	
	rows = input(rows,"rows");
    cols = input(cols,"cols");
    size_t edge = (rows + 1) * cols + (cols + 1) * rows;
    unsigned int matrix_size = (rows + 1) * (cols + 1);
    char **grid = new char*[matrix_size];

    for (size_t i = 0; i < matrix_size; ++i)
    {
        grid[i] = new  char[matrix_size];
    }
    get_adj_matrix(grid, cols, rows);
    char isMade = grid[0][1];
    if (isMade == '1' && matrix_size < 53)
    {
        print_adj_matrix(grid, rows, cols);
    }
    print_graph(rows, cols);
    if (edge % 3 == 0)
    {
        threeLenghtSimpleChainCoverage(rows, cols);
        printCoverage(rows, cols);
        for (size_t i = 0; i < matrix_size; ++i)
        {
            delete []grid[i];
        }
        delete []grid;
    }
    else
    {
        std::cout<<"\033[1;35mGRAPH HAS " << edge << " EDGES\n";
        std::cout<<"\033[1;31mNO COVERAGE\033[0m\n";
        std::ofstream myFile("data/coverage.txt", std::ofstream::out | std::ofstream::trunc);
        myFile << "GRAPH HAS NO COVERAGE";
		for (size_t i = 0; i < matrix_size; ++i)
        {
            delete []grid[i];
        }
        delete []grid;
    }
}


