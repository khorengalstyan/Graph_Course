#include <fstream>
#include <iostream>
#include <list>
#include <string>

#include "../include/input.hpp"
#include "../include/matrixes.hpp"
#include "../include/print_graph.hpp"
#include "../include/solution.hpp"


int main()
{
	cbreak();
	system("clear");	
	bool cycle = true; 
	const int UP = 65;
	const int DOWN = 66;
	const int ENTER = 10;
	int rows = 1;	
	std::cout << "\033[1;32mrows : " << rows<<" ↑ ↓\033[0m" << std::endl;
	while(cycle == true)
	{
		cbreak();
		const int key = keypress();
		switch(key)
		{
			case UP:
			{
				system("clear");
				++rows;	
				std::cout << "\033[1;32mrows : " << rows<<" ↑ ↓\033[0m" << std::endl;
				break;
			}
			case  DOWN:
			{	
				if (rows > 1)
				{
					system("clear");
					--rows;
					std::cout<<"\033[1;32mrows : " << rows << " ↑ ↓\033[0m" << std::endl;
					break;
				}	
				else
				{
					break;
				}
			}
			case ENTER:
			{
				goto input_cols;
			}
		}
	}

input_cols:
	system("clear");
	int cols = 1;
	std::cout << "\033[1;32mcols : " << cols<<" ↑ ↓\033[0m" << std::endl;
	while(cycle == true)
	{
		cbreak();
		const int key = keypress();
		switch(key)
		{
			case UP:
			{
				system("clear");
				++cols;
				std::cout << "\033[1;32mcols : " << cols << " ↑ ↓\033[0m" << std::endl;
				break;
			}
			case  DOWN:
			{
				if (cols > 1)
				{
					system("clear");
					--cols;
					std::cout << "\033[1;32mcols : " << cols << " ↑ ↓\033[0m" << std::endl;
					break;
				}
				else
				{
					break;
				}
			}
			case ENTER:
			{
				goto solution;
			}
		}
	}

solution:        
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
	normal();
	return 0;
}
