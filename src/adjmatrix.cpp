#include <iostream>
#include <fstream>

void get_matrix(int **grid, unsigned int rows, unsigned int cols)
{
	std :: ofstream myFile("matrix.txt", std::ofstream::out | std::ofstream::trunc);
	unsigned int lineHor = cols + 1;
	unsigned int lineVer = rows + 1;
	for (unsigned int i = 0; i < lineHor * lineVer; ++i)
	{
		for (unsigned int j = 0; j < lineHor * lineVer; ++j)
		{
			grid[i][j] = 0;
		}
	}

	for (unsigned int i = 0; i < lineVer * lineHor - lineVer; ++i)
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

	for (unsigned int i = lineHor*lineVer - 1; i > lineVer * lineHor - lineVer; --i)
	{
        {
            grid[i][i-1] = grid[i-1][i] = 1;
        }
	}
 	for (unsigned int i = 0; i < lineHor * lineVer; ++i)
    {
        for (unsigned int j = 0; j < lineHor * lineVer; ++j)
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
	std :: cout << "\n\nADJACENCY MATRIX OF " << rows << "*" << cols << " SQUARE GRID \n\n\n";
	for (size_t i = 0; i < (lineHor)*(lineVer);++i)
	{
		if (i == 0)
		{
			std :: cout << "   " << i << " ";
		}
		else
		{
			std :: cout << i << " ";
		}
		
	}
	std :: cout << "\n";
	for (size_t i = 0; i < (lineHor) * (lineVer); ++i)
	{
		if (i < 10)
		{
			std :: cout << i << "  "; 
		}
		else if (i >= 10 && i <=99)
		{
			std :: cout << i << " ";
		}
		else
		{
			std :: cout << i;
		}
		
		for (size_t j = 0; j < (lineHor) * (lineVer); ++j)
		{
			if (j < 10)
			{
				if (grid[i][j] == 0)
				{
					std :: cout << grid[i][j] << " ";
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
					std :: cout << grid[i][j] << "  ";
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
					std :: cout << grid[i][j] << "   ";
				}
				else
				{
					std :: cout << "\033[1;31m" << grid[i][j] << "   \033[0m";
				}
			}

		}
		std :: cout << "\n";
	}
}

