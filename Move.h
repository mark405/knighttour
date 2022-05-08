#pragma once

#include <vector>
#include "WarnsdoffAlgorithm.h"

#define N 8

class Move
{
public:
	bool neighbour(int rowStart, int colStart, int rowEnd, int colEnd, std::vector<std::vector<int>> possibleOptions); //checking if first move is close to last one
	bool isValid(std::vector<std::vector<int>>& table, int row, int col); //checking if moving knight is possible on position row, col
	bool nextMove(std::vector<std::vector<int>>& table, int& row, int& col, std::vector<std::vector<int>> possibleOptions); // moving knight
};


