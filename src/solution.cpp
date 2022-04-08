#include <iostream>
#include <list>
#include <tuple>

#include "../include/globals.hpp"
#include "../include/solution.hpp"

using threeLenghtChain = std::tuple<int, int, int, int>;
std::list <threeLenghtChain> threeLenghtChains;

void threeLenghtSimpleChainCoverage(unsigned int hor, unsigned int ver)
{
	edge = hor*(ver+1) + ver*(hor+1);
    std :: cout << "\033[1;35mGraph has " <<  edge << " edges\n" ;
    if (edge % 3 != 0)
    {
        std :: cout << "\033[1;31mNO COVERAGE\033[0m\n";
    }

	else
	{	
		if (hor % 3 == 0 && ver % 3 == 0)
		{
			for (size_t i = 0; i < hor + 1; ++i)
			{
				for (size_t j = 0; j < ver ; j+=3)
				{
					threeLenghtChains.push_back(std::make_tuple(i*ver+j+i,i*ver + i + j + 1, i*ver + i + j + 2, i*ver + i + j + 3));
				}
			}

			for (size_t i = 0; i < ver+1; ++i)
			{
				for (size_t j = 0; j < hor; j+=3)
				{
					threeLenghtChains.push_back(std::make_tuple(j*(ver+1) + i, (j+1)*(ver+1) + i, (j+2)*(ver+1) + i , (j+3)*(ver+1) + i));
				}
			}
		}

		else
	
		{
			for (size_t i = 0; i < hor ; ++i)
			{
				for (size_t j = 0; j < ver + 1; j+=3)
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

			for (size_t i = 0; i < ver; ++i)
			{
				for (size_t j = 0; j < hor; j+=3)
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
}

void printCoverage()
{
	if (edge % 3 == 0)
	{		
		std::cout << "\033[1;32m	COVERAGE\033[0m" << std::endl;
		size_t count = 0;
		for (const auto& i : threeLenghtChains)
		{	
			std::cout<<"\033[1;31m"<<count + 1<<"\033[0m. ";
			std::cout  << "\033[1;34m" << std::get<0>(i) << " --> " << std::get<1>(i) << " --> " << std::get<2>(i) << " --> " << std::get<3>(i) << "\033[0m" << std::endl;
			++count;
		}
		
		std::cout << std::endl;
    }
}
