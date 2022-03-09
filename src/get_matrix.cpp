#include <iostream>

void get_matrix(int **grid, int rows, int cols)
{
	const int lineHor = cols + 1;
	const int lineVer = rows + 1;
	for (int i = 0; i < lineHor * lineVer; ++i)
	{
		for (int j = 0; j < lineHor * lineVer; ++j)
		{
			grid[i][j] = 0;
		}
	}

	for (int i = 0; i < (lineVer) * (lineHor) - (lineVer); ++i)
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

	for (int i = (lineHor)*(lineVer) - 1; i > (lineVer)*(lineHor)-(lineVer); --i)
	{
        {
            grid[i][i-1] = grid[i-1][i] = 1;
        }
	}
}

