#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "../include/graphViz.hpp"
#include "../include/matrixes.hpp"
#include "../include/inputSize.hpp"
#include "../include/printAscii.hpp"
#include "../include/input.hpp"
#include "../include/gotoXY.hpp"

void graphViz()
{
	size_t rows, cols;
	rows = inputSize(rows,"rows","printGraphViz");
	cols = inputSize(cols,"cols","printGraphViz");
    size_t edge = (rows + 1) * cols + (cols + 1) * rows;
	size_t matrixSize = (rows + 1) * (cols + 1);
    std::vector<std::vector<char>> graphViz(matrixSize, std::vector<char>(matrixSize));
    getAdjacencyMatrix(graphViz, cols, rows);
    std::ofstream GraphViz("data/GraphViz.dot", std::ofstream::out | std::ofstream::trunc);
	GraphViz<<"graph G {\n";
	for (size_t i = 1; i < matrixSize; ++i)
	{
		for (size_t j = 0; j < i; ++j)
		{
			if (graphViz[i][j] == '1')
			{
				GraphViz<<i<<" -- "<<j<<"  \n";
			}
		}
	}
    GraphViz<<"}";
	GraphViz.close();
	system("dot -Tpng -O data/GraphViz.dot && xdg-open data/GraphViz.dot.png");
	gotoXY(40,50);
	std::cout<<"\033[1;34m Graph Vizualization is now in data directory\033[0m\n";
}
