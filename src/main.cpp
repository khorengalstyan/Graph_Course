#include <iostream>
#include <list>
#include <string>

#include "../include/globals.hpp"
#include "../include/matrixes.hpp"
#include "../include/print_graph.hpp"
#include "../include/solution.hpp"


int main()
{	
	int rows_number,cols_number;		
	std :: cout << "rows number in range [1,20] = ";
	std :: cin >> rows_number;
    std :: cout << "cols number in range [1,20] = ";
    std :: cin >> cols_number;
    
	unsigned int matrix_size = (rows_number+1) * (cols_number+1);
	char **grid = new char*[matrix_size];
	
	for (size_t i = 0; i < matrix_size; ++i)
	{
		grid[i] = new  char[matrix_size];
	}
	print_graph(rows_number, cols_number);
	get_adj_matrix(grid,cols_number,rows_number);
	char isMade = grid[0][1];
	if (isMade == '1' && matrix_size < 53)
	{
		print_adj_matrix(grid,rows_number,cols_number);
	}
	if (edge % 3 == 0)
	{
		threeLenghtSimpleChainCoverage(rows_number, cols_number);
		printCoverage(rows_number, cols_number);
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
