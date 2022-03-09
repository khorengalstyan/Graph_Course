#include <iostream>

void print_matrix(int **grid, const int rows, const int cols)
{
	const int lineHor = cols + 1;
	const int lineVer = rows + 1;
	std :: cout << "MATRIX OF RESSURETION\n";
	for (int i = 0; i < (lineHor)*(lineVer);++i)
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
	for (int i = 0; i < (lineHor) * (lineVer); ++i)
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
		
		for (int j = 0; j < (lineHor) * (lineVer); ++j)
		{
			if (j < 10)
			{
				std :: cout << grid[i][j] << " ";
			}
			else if (j >= 10 && j <= 99)
			{
				std :: cout << grid[i][j] << "  ";
			}
			else
			{
				std :: cout << grid[i][j] << "   ";
			}

		}
		std :: cout << "\n";
	}
}

