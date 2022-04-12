#include <fstream>
#include <iostream>
#include <list>
#include <tuple>

#include "../include/globals.hpp"
#include "../include/solution.hpp"

using threeLenghtChain = std::tuple<size_t, size_t, size_t, size_t>;
std::list <threeLenghtChain> threeLenghtChains;

void threeLenghtSimpleChainCoverage(unsigned int rows, unsigned int cols)
{
	edge = rows*(cols+1) + cols*(rows+1);
    
    if (edge % 3 != 0)
    {
		std::cout<<"\033[1;35mGRAPH HAS " << edge << " EDGES\n";
        std :: cout << "\033[1;31mNO COVERAGE\033[0m\n";
    }
	else
	{	
		std :: cout << "\033[1;35mGRAPH HAS " <<  edge << " EDGES AND CAN BE COVERED BY " << edge/3 << " THREE LENGTH SIMPLE CHAINS\n";
		if (rows % 3 == 0 && cols % 3 == 0)
		{
			for (size_t i = 0; i < rows + 1; ++i)
			{
				for (size_t j = 0; j < cols ; j+=3)
				{
					threeLenghtChains.push_back(std::make_tuple(i*cols+j+i,i*cols + i + j + 1, i*cols + i + j + 2, i*cols + i + j + 3));
				}
			}

			for (size_t i = 0; i < cols+1; ++i)
			{
				for (size_t j = 0; j < rows; j+=3)
				{
					threeLenghtChains.push_back(std::make_tuple(j*(cols+1) + i, (j+1)*(cols+1) + i, (j+2)*(cols+1) + i , (j+3)*(cols+1) + i));
				}
			}
		}
		else
		{
			for (size_t i = 0; i < rows ; ++i)
			{
				for (size_t j = 0; j < cols + 1; j+=3)
				{
					if (j != cols - 2)
					{
						threeLenghtChains.push_back(std::make_tuple(i*cols+j+i,i*cols + i + j + 1, i*cols + i + j + 2, i*cols + i + j + 3));
					}
					else
					{
						threeLenghtChains.push_back(std::make_tuple(i*cols+j+i,i*cols + i + j + 1, i*cols + i + j + 2, i*cols + 2*cols + 1 + i));
					}
				}
			}

			for (size_t i = 0; i < cols; ++i)
			{
				for (size_t j = 0; j < rows; j+=3)
				{
					if (j != rows - 2)
					{
						threeLenghtChains.push_back(std::make_tuple(j*(cols+1) + i, (j+1)*(cols+1) + i, (j+2)*(cols+1) + i , (j+3)*(cols+1) + i));
					}
					else
					{
						threeLenghtChains.push_back(std::make_tuple(j*(cols+1) + i, (j+1)*(cols+1) + i, (j+2)*(cols+1) + i , (j+2)*(cols+1) + i + 1));
					}
				}
			}
		}
	}
}

void printCoverage(unsigned int rows, unsigned int cols)
{
	edge = rows*(cols+1) + cols*(rows+1);
	std :: ofstream myFile("data/coverage.txt", std::ofstream::out | std::ofstream::trunc);
	if (edge % 3 == 0)
	{		
		std::cout << "\033[1;32m		       COVERAGE\033[0m" << std::endl;
		size_t count = 0;
		for (const auto& i : threeLenghtChains)
		{	
			myFile << count + 1 << ") "  << std::get<0>(i) << " --> " << std::get<1>(i) << " --> " << std::get<2>(i) << " --> " << std::get<3>(i) << "\n";
			std::cout << "\033[1;31m              " << count + 1 << ") \033[0m" << "\033[1;34m" << std::get<0>(i) << " --> " << std::get<1>(i) << " --> " << std::get<2>(i) << " --> " << std::get<3>(i) << "\033[0m\n";
			++count;
		}
		std::cout << std::endl;
    }
	else
	{
		myFile << "GRAPH HAS NO COVERAGE";
	}
	myFile.close();
}
