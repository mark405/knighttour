#pragma once

#include "Printer.h"
#include "Move.h"

class WarnsdoffAlgorithm
{
public: 
	void optimizeByWarnsdoffAlgorithm(
		std::vector<std::vector<int>>& table, int& index,
		int& minCount, int rowStart,
		int colStart,
		std::vector<std::vector<int>> possibleOptions); //finding move that has minimum next moves	
};


