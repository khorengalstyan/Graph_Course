#include <fstream>
#include <iostream>
#include <tuple>
#include <vector>

#include "../include/coverage.hpp"
#include "../include/gotoXY.hpp"

using threeLenghtChain = std::tuple<size_t, size_t, size_t, size_t>;
std::vector<threeLenghtChain> threeLengthChains;

void threeLenghtSimpleChainCoverage(size_t rows, size_t cols)
{
	size_t edge = rows * (cols + 1) + cols * (rows + 1);
    
	if (rows % 3 == 0 && cols % 3 == 0)
	{
		for (size_t i = 0; i < rows + 1; ++i)
		{
			for (size_t j = 0; j < cols ; j += 3)
			{
				threeLengthChains.push_back(std::make_tuple(i * cols + j + i, i * cols + i + j + 1, i * cols + i + j + 2, i * cols + i + j + 3));
			}
		}

		for (size_t i = 0; i < cols + 1; ++i)
		{
			for (size_t j = 0; j < rows; j += 3)
			{
				threeLengthChains.push_back(std::make_tuple(j * (cols + 1) + i, (j + 1) * (cols + 1) + i, (j + 2) * (cols + 1) + i , (j + 3) * (cols + 1) + i));
			}
		}
	}
	else
	{
		for (size_t i = 0; i < rows ; ++i)
		{
			for (size_t j = 0; j < cols + 1; j += 3)
			{
				if (j != cols - 2)
				{
					threeLengthChains.push_back(std::make_tuple(i * cols + j + i, i * cols + i + j + 1, i * cols + i + j + 2, i * cols + i + j + 3));
				}
				else
				{
					threeLengthChains.push_back(std::make_tuple(i * cols + j + i, i * cols + i + j + 1, i * cols + i + j + 2, i * cols + 2 * cols + 1 + i));
				}
			}
		}

		for (size_t i = 0; i < cols; ++i)
		{
			for (size_t j = 0; j < rows; j += 3)
			{
				if (j != rows - 2)
				{
					threeLengthChains.push_back(std::make_tuple(j * (cols + 1) + i, (j + 1) * (cols + 1) + i, (j + 2) * (cols + 1) + i , (j + 3) * (cols + 1) + i));
				}
				else
				{
					threeLengthChains.push_back(std::make_tuple(j * (cols + 1) + i, (j + 1) * (cols + 1) + i, (j + 2) * (cols + 1) + i , (j + 2) * (cols + 1) + i + 1));
				}
			}
		}
	}
}

void printCoverage(size_t rows, size_t cols)
{
	size_t edges = rows * (cols + 1) + cols * (rows + 1);
	std::ofstream myFile("data/coverage.txt", std::ofstream::out | std::ofstream::trunc);
		
	if (edges % 3 == 0 && edges != 0)
	{		
		std::cout << "\033[1;32m	COVERAGE\033[0m" << std::endl;
		size_t count = 0;
		myFile<<"Coverage of " << rows << " * " << cols <<" grid graph\n";
		for (size_t i = 0; i < threeLengthChains.size(); ++i)
		{	
			myFile << count + 1 << ") "  << std::get<0>(threeLengthChains[i]) << " --> " << std::get<1>(threeLengthChains[i]) << " --> " << std::get<2>(threeLengthChains[i]) << " --> " << std::get<3>(threeLengthChains[i]) << "\n";
			std::cout << "\033[1;31m" << count + 1 << ") \033[0m" << "\033[1;34m" << std::get<0>(threeLengthChains[i]) << " --> " << std::get<1>(threeLengthChains[i]) << " --> " << std::get<2>(threeLengthChains[i]) << " --> " << std::get<3>(threeLengthChains[i]) << "\033[0m\n";
			++count;
		}
		std::cout << std::endl;
    }
	threeLengthChains.clear();
	myFile.close();
}

void printNoCoverage(size_t rows, size_t cols)
{
    std::cout<<"\033[1;31m  HAS NO COVERAGE\033[0m\n";
	std::ofstream myFile("data/coverage.txt", std::ofstream::out | std::ofstream::trunc);
	myFile<<rows<<" * "<<cols<<" grid graph has no ceverage\n";
}

