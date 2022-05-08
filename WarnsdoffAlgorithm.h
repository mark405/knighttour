#pragma once

#include "Printer.h"
#include "Move.h"

class WarnsdoffAlgorithm
{
private:
	const std::vector<std::vector<int>> possibleOptions
	{
			{1, 1,  2, 2,  -1, -1, -2, -2},
			{2, -2, 1, -1, 2,  -2, 1,  -1}
	};
public: 
	void optimizeByWarnsdoffAlgorithm(
		std::vector<std::vector<int>>& table, int& index,
		int& minCount, int rowStart,
		int colStart); //finding move that has minimum next moves	
};

