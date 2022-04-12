#include <iostream>
#include <list>
#include <string>

#include "../include/globals.hpp"
#include "../include/matrixes.hpp"
#include "../include/print_graph.hpp"
#include "../include/solution.hpp"
#include "../include/valid_input.hpp"


int main()
{	
	std::string rows_number;	
	int rows;	
	rows = validInputRows(rows_number);
	std::string cols_number;
	int cols;		
	cols = validInputCols(cols_number);

	unsigned int matrix_size = (rows+1) * (cols+1);
	char **grid = new char*[matrix_size];
	
	for (size_t i = 0; i < matrix_size; ++i)
	{
		grid[i] = new  char[matrix_size];
	}
	get_adj_matrix(grid,cols,rows);
	char isMade = grid[0][1];
	if (isMade == '1' && matrix_size < 53)
	{
		print_adj_matrix(grid,rows,cols);
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
		for (size_t i = 0; i < matrix_size; ++i)
		{
    		delete []grid[i];
		}
		delete []grid;
	}
	return 0;
}
