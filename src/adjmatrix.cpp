#include <iostream>
#include <fstream>
#include <utility>
#include <list>
#include <tuple>
#include <../include/adjmatrix.hpp>

extern size_t edge = 0;

using threeLenghtChain = std::tuple<int, int, int, int>;
std::list<threeLenghtChain> threeLenghtChains;



void get_matrix(int **grid, unsigned int rows, unsigned int cols)
{
	std :: ofstream myFile("data/matrix.txt", std::ofstream::out | std::ofstream::trunc);
	unsigned int lineHor = cols + 1;
	unsigned int lineVer = rows + 1;
	
	for (size_t i = 0; i < lineHor * lineVer; ++i)
	{
		for (size_t j = 0; j < lineHor * lineVer; ++j)
		{
			grid[i][j] = 0;
		}
	}

	for (size_t i = 0; i < lineVer * lineHor - lineVer; ++i)
    {
    	if (i % (lineVer) != rows)
		{
			grid[i][i+1] = grid[i][i+lineVer] = grid[i+1][i] = grid[i+lineVer][i] = 1;
		}
		else
		{
			grid[i][i+lineVer] = grid[i+lineVer][i] = 1;
		}
    }

	for (size_t i = lineHor*lineVer-1 ; i > lineVer * lineHor - lineVer; --i)
	{
        {
            grid[i][i-1] = grid[i-1][i] = 1;
        }
	}

 	for (size_t i = 0; i < lineHor * lineVer; ++i)
    {
        for (size_t j = 0; j < lineHor * lineVer; ++j)
        {
			myFile << grid[i][j];
		}
		myFile << "\n";
	}
	myFile.close();


}


void print_matrix(int **grid, unsigned int rows, unsigned int cols)
{
	const unsigned int lineHor = cols + 1;
	const unsigned int lineVer = rows + 1;
	std :: cout << "\033[1;36mADJACENCY MATRIX OF " << rows << "*" << cols << " SQUARE GRID \033[0m\n\n";
	
	for (size_t i = 0; i < (lineHor)*(lineVer);++i)
	{
		if (i == 0)
		{
			std :: cout << "\033[1;33m   " << i << " \033[0m";
		}
		else
		{
			std :: cout << "\033[1;33m" << i << " \033[0m";
		}
	}
	std :: cout << "\n";
	
	for (size_t i = 0; i < (lineHor) * (lineVer); ++i)
	{
		if (i < 10)
		{
			std :: cout << "\033[1;33m" << i << "  \033[0m";
		}
		else if (i >= 10 && i <=99)
		{
			std :: cout << "\033[1;33m" << i << " \033[0m";
		}
	 	else
		{
			std :: cout << "\033[1;33m" << i << "\033[0m";
		}
		
		for (size_t j = 0; j < (lineHor) * (lineVer); ++j)
		{
			if (j < 10)
			{
				if (grid[i][j] == 0)
				{
					std :: cout << "\033[1;32m" << "." << " \033[0m";
				}
				else
				{
					std :: cout << "\033[1;31m" << grid[i][j] << " \033[0m";
				}
			}
			else if (j >= 10 && j <= 99)
			{
				if (grid[i][j] == 0)
				{
					std :: cout << "\033[1;32m" << "." << "  \033[0m";
				}
				else
				{
					std :: cout << "\033[1;31m" << grid[i][j] << "  \033[0m";
				}
			}
			else
			{
				if (grid[i][j] == 0)
				{
					std :: cout << "\033[1;32m" << "." << "   \033[0m";
				}
				else
				{
					std :: cout << "\033[1;31m" << grid[i][j] << "   \033[0m";
				}
			}
		}
		std :: cout << "\n";
	}

	edge = cols*(rows+1) + rows*(cols+1);
	std :: cout << "\033[1;35mGraph has " <<  edge << " edges\n" ;
	if (edge % 3 != 0)
	{
		std :: cout << "\033[1;36mNo Coverage\033[0m\n";
	}
}


void threeLenghtSimpleChainCoverage(int hor, int ver)
{
	if (hor % 3 == 0 && ver % 3 == 0)
	{
		for (int i = 0; i < hor + 1; ++i)
		{
			for (int j = 0; j < ver ; j+=3)
			{
				threeLenghtChains.push_back(std::make_tuple(i*ver+j+i,i*ver + i + j + 1, i*ver + i + j + 2, i*ver + i + j + 3));
			}
		}

		for (int i = 0; i < ver+1; ++i)
		{
			for (int j = 0; j < hor; j+=3)
			{
				threeLenghtChains.push_back(std::make_tuple(j*(ver+1) + i, (j+1)*(ver+1) + i, (j+2)*(ver+1) + i , (j+3)*(ver+1) + i));
			}
		}
	}

	else
	
	{
		for (int i = 0; i < hor ; ++i)
		{
			for (int j = 0; j < ver + 1; j+=3)
			{
				if (j != ver - 2)
				{
					threeLenghtChains.push_back(std::make_tuple(i*ver+j+i,i*ver + i + j + 1, i*ver + i + j + 2, i*ver + i + j + 3));
				}
				else
				{
					threeLenghtChains.push_back(std::make_tuple(i*ver+j+i,i*ver + i + j + 1, i*ver + i + j + 2, i*ver + 2*ver + 1 + i));
				}
			}
		}

		for (int i = 0; i < ver; ++i)
		{
			for (int j = 0; j < hor; j+=3)
			{
				if (j != hor - 2)
				{
					threeLenghtChains.push_back(std::make_tuple(j*(ver+1) + i, (j+1)*(ver+1) + i, (j+2)*(ver+1) + i , (j+3)*(ver+1) + i));
				}
				else
				{
					threeLenghtChains.push_back(std::make_tuple(j*(ver+1) + i, (j+1)*(ver+1) + i, (j+2)*(ver+1) + i , (j+2)*(ver+1) + i + 1));
				}
			}
		}
	}
}

void printCoverage()
{
	std::cout << ".......Three Lenght Simple Chains......." << std::endl;
	for (const auto& it : threeLenghtChains)
	{
		std::cout  << std::get<0>(it) << " " << std::get<1>(it) << " " << std::get<2>(it) << " " << std::get<3>(it) << std::endl;
	}
	std::cout << std::endl;
}