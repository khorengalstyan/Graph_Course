#include <fstream>
#include <iostream>

#include "../include/printGraph.hpp"

void printGraph(unsigned int cols, unsigned int rows)
{
	const unsigned int lineHor = cols + 1;
	const unsigned int lineVer = rows + 1;
	std::string **matrix = new std::string*[5 * lineHor];
	
	for (size_t i = 0; i < 5 * lineHor; ++i)
	{
		matrix[i] = new std::string[7 * lineVer];
	}

	for (size_t i = 0; i < 5 * lineHor; ++i)
	{
    	for (size_t j = 0; j < 7 * lineVer; ++j)
		{
			matrix[i][j] = ' ';
		}
	}

	for (size_t i = 0; i < 5 * lineHor; ++i)
	{
		for (size_t j = 0; j < 7 * lineVer; ++j)
		{
			if (i % 5 == 0)
			{
				matrix[i][j] = '_';
			}
			if (j % 7 == 0)
			{
				matrix[i][j] = '|';
			}
		}
	}
	
	std:: string split_string;
	
	for (size_t i = 0; i < 5 * lineHor; i += 5)
	{
		for (size_t j = 0; j < 7 * lineVer; j += 7)
		{
			if (i == 0)
			{
				std::string c = std::__cxx11::to_string(j / 7);
				if (c.length() > 1)
				{
					for (size_t t = 0; t < c.length(); ++t)
					{
						split_string[t] = c[t];
					}
					
					for (size_t p = 0; p < c.length(); ++p)
                	{
                    	matrix[i][j + p] = split_string[p];                   
                	}
				}
				else 
				{
					matrix[i][j] = c;
				}
			}
			else
			{
				std::string c = std::__cxx11::to_string(i / 5 + j / 7 + (i / 5) * rows);
                if (c.length() > 1)
                {
                    for (size_t t = 0; t < c.length(); ++t)
                    {
                        split_string[t] = c[t];
                    }

					for (size_t p = 0; p < c.length(); ++p)
                	{
                    	if (j != 0)
                    	{
                        	matrix[i][j + p - 1] = split_string[p];
                    	}
						else
						{
							matrix[i][j + p] = split_string[p];
						}
                	}
                }
				else 
				{
					matrix[i][j] = c;
				}   
			}
		}
	}

	size_t visibleVerSize = 5 * lineHor - 4;
	size_t visibleHorSize = 7 * lineVer - 6;
	
	if (rows < 22)
	{
		for (size_t i = 0; i < visibleVerSize; ++i)
		{
			if (matrix[i][7 * rows + 1] == "_")
			{
				for (size_t j = 0; j < visibleHorSize; ++j)
				{
					std::cout << "\033[1;35m" << matrix[i][j] << "\033[0m";
				}
			} 
			else
			{
				for (size_t j = 0; j < visibleHorSize + 1; ++j)
   	         	{
					std::cout << "\033[1;35m" << matrix[i][j] << "\033[0m";
	            }
			}
			std::cout << "\n";
		}
	}
	
	std::ofstream myFile("data/graph.txt", std::ofstream::out | std::ofstream::trunc);
	for (size_t i = 0; i < visibleVerSize; ++i)
	{
		if (matrix[i][7 * rows + 1] == "_")
		{
			for (size_t j = 0; j < visibleHorSize; ++j)
			{
				myFile << matrix[i][j];
			}
		}
		else
		{
			for (size_t j = 0; j < visibleHorSize + 1; ++j)
            {
				myFile << matrix[i][j];
            }
		}
		myFile << "\n";
	}

	for (size_t i = 0; i < 5* lineHor; ++i)
    {
        delete []matrix[i];
    }
    delete []matrix;
}

