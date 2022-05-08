#pragma once

#include <vector>
#include "WarnsdoffAlgorithm.h"

#define N 8

class Move
{
private: 
	const std::vector<std::vector<int>> possibleOptions
	{
			{1, 1,  2, 2,  -1, -1, -2, -2},
			{2, -2, 1, -1, 2,  -2, 1,  -1}
	};
public:
	bool neighbour(int rowStart, int colStart, int rowEnd, int colEnd); //checking if first move is close to last one
	bool isValid(std::vector<std::vector<int>>& table, int row, int col); //checking if moving knight is possible on position row, col
	bool nextMove(std::vector<std::vector<int>>& table, int& row, int& col); // moving knight
};

