#pragma once

#include <vector>
#include <string>

class Printer//class that has all methods related to printing table and messages
{
public:
	void printTable(std::vector<std::vector<int>>& table); //printing matrix
	void printResultErrorMessage(int row, int col);//printing error message
	void printResultSuccessMessage(int row, int col);//printing success message
	void printDeadEndMessage(int row, int col);//printing message when got in trap
	void printIncorrectInputMessage();//printing message when user chooses incorrect menu item
};

