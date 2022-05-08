#pragma once

#include <vector>
#include <string>

class Printer
{
public:
	void printTable(std::vector<std::vector<int>>& table); //printing matrix
	void printResultErrorMessage(int row, int col);  
	void printResultSuccessMessage(int row, int col);
	void printDeadEndMessage(int row, int col);
	void printIncorrectInputMessage();   
};

