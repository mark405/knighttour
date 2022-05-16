#pragma once
#include <vector>
#define N 8 

class Move //class that has all methods related to the movement of a knight
{
public:
	bool neighbour(int rowStart, int colStart, int rowEnd, int colEnd, const std::vector<std::vector<int>> possibleOptions); //checking if first move is close to last one
	bool isValid(std::vector<std::vector<int>>& table, int row, int col); //checking if moving knight is possible on position row, col
	bool nextMove(std::vector<std::vector<int>>& table, int& row, int& col, const std::vector<std::vector<int>> possibleOptions); // moving knight
	void optimizeByWarnsdoffAlgorithm(
		std::vector<std::vector<int>>& table, int& index,
		int& minCount, int rowStart,
		int colStart,
		const std::vector<std::vector<int>> possibleOptions); //finding move that has minimum next moves	
};


