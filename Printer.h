#pragma once

#include <vector>
#include <string>

class Printer
{
public:
	void printTable(std::vector<std::vector<int>>& table); //printing matrix
	void printResultErrorMessage(char col, int row);
	void printResultSuccessMessage(char col, int row);
    void printDeadEndMessage(char col, int row);
	void printIncorrectInputMessage();
};

