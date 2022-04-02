#include <cstdlib>
#include <iostream>
#include <string>
#include "../include/print_graph.hpp"
#include "../include/adjmatrix.hpp"

size_t extern edge;
int main()
{	
	int rows_number,cols_number;	
	do
	{	
		std :: cout << "rows number in range [1,20] = ";
		std :: cin >> rows_number;
	} while (rows_number <= 0 || rows_number > 20);
		
	do
    {
        std :: cout << "cols number in range [1,20] = ";
        std :: cin >> cols_number;
    } while (cols_number <= 0 || cols_number > 20);
	unsigned int matrix_size = (rows_number+1) * (cols_number+1);
	int **grid = new int*[matrix_size];
	
	for (size_t i = 0; i < matrix_size; ++i)
	{
		grid[i] = new  int[matrix_size];
	}
	print_graph(rows_number, cols_number);
	get_matrix(grid,cols_number,rows_number);
	print_matrix(grid,rows_number,cols_number);
	if (edge % 3 == 0)
	{
		threeLenghtSimpleChainCoverage(rows_number, cols_number);
		printCoverage();
		for (size_t i = 0; i < matrix_size; ++i)
		{
    		delete []grid[i];
		}
		delete []grid;
		return 0;
	}
	else
	{
		for (size_t i = 0; i < matrix_size; ++i)
		{
    		delete []grid[i];
		}
		delete []grid;
		return 0;
	}
}
