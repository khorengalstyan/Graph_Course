#include <fstream>
#include <iostream>

#include <../include/matrixes.hpp>

void getAdjacencyMatrix(std::vector<std::vector<char>> & grid, unsigned int rows, unsigned int cols)
{
	system("clear");
	std::ofstream myFile("data/adjacency_matrix.txt", std::ofstream::out | std::ofstream::trunc);
	const unsigned int lineHor = cols + 1;
	const unsigned int lineVer = rows + 1;
	
	for (size_t i = 0; i < lineHor * lineVer; ++i)
	{
		for (size_t j = 0; j < lineHor * lineVer; ++j)
		{
			grid[i][j] = '.';
		}
	}

	for (size_t i = 0; i < lineVer * lineHor - lineVer; ++i)
    {
    	if (i % lineVer != rows)
		{
			grid[i][i + 1] = grid[i][i + lineVer] = grid[i + 1][i] = grid[i + lineVer][i] = '1';
		}
		else
		{
			grid[i][i + lineVer] = grid[i + lineVer][i] = '1';
		}
    }

	for (size_t i = lineHor * lineVer - 1 ; i > lineVer * lineHor - lineVer; --i)
	{
        {
            grid[i][i - 1] = grid[i - 1][i] = '1';
        }
	}
	
	for (size_t i = 0; i < lineHor * lineVer; ++i)
	{
		if (i == 0)
		{
			myFile << "   " << i;
		}
		else
		{
			myFile << " " << i;
		}
	}

	myFile << "\n";
	
	for (size_t i = 0; i < lineHor * lineVer; ++i)
	{
		if (i < 10)
		{
			myFile << i << "  ";
		}
		else if (i >= 10 && i <=99)
		{
			myFile << i << " ";
		}
	 	else
		{
			myFile << i;
		}
		
		for (size_t j = 0; j < lineHor * lineVer; ++j)
		{
			if (j < 10)
			{
				myFile << grid[i][j] << " ";
			}
			else if (j >= 10 && j <= 99)
			{	
				myFile << grid[i][j] << "  ";		
			}
			else
			{
				myFile  << grid[i][j] << "   ";
			}
		}
		myFile << "\n";
	}
	myFile.close();
}
 	
void printAdjacencyMatrix(std::vector<std::vector<char>> & grid, unsigned int rows, unsigned int cols)
{
	const unsigned int lineHor = cols + 1;
	const unsigned int lineVer = rows + 1;
	std::cout << "\033[1;36mADJACENCY MATRIX OF " << rows << " * " << cols << " SQUARE GRID \033[0m\n\n";
	
	for (size_t i = 0; i < lineHor * lineVer; ++i)
	{
		if (i == 0)
		{
			std::cout << "\033[1;33m   " << i << " \033[0m";
		}
		else
		{
			std::cout << "\033[1;33m" << i << " \033[0m";
		}
	}
	
	std::cout << "\n";
	
	for (size_t i = 0; i < lineHor * lineVer; ++i)
	{
		if (i < 10)
		{
			std::cout << "\033[1;33m" << i << "  \033[0m";
		}
		else if (i >= 10 && i <=99)
		{
			std::cout << "\033[1;33m" << i << " \033[0m";
		}
	 	else
		{
			std::cout << "\033[1;33m" << i << "\033[0m";
		}
		
		for (size_t j = 0; j < lineHor * lineVer; ++j)
		{
			if (j < 10)
			{
				if (grid[i][j] == '1')
				{
					std::cout << "\033[1;32m" << grid[i][j] << " \033[0m";
				}
				else
				{
					std::cout << "\033[1;31m" << grid[i][j] << " \033[0m";
				}
			}
			
			else if (j >= 10 && j <= 99)
			{	
				if (grid[i][j] == '1')
				{
					std::cout << "\033[1;32m" << grid[i][j] << "  \033[0m";
				}
				else
				{
					std::cout << "\033[1;31m" << grid[i][j] << "  \033[0m";
				}
			}
			else
			{	
				if (grid[i][j] == '1')
				{
					std::cout << "\033[1;32m" << grid[i][j] << "   \033[0m";
				}
				else
				{
					std::cout << "\033[1;31m" << grid[i][j] << "   \033[0m";
				}
			}
		}
		std::cout << "\n";
	}	
}
