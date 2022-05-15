#pragma once

#include <vector>
#include <string>

class Printer//class that has all methods related to printing table and messages
{
public:
	void printTable(std::vector<std::vector<int>>& table); //printing matrix
	void printResultErrorMessage(char col, int row);//printing error message
	void printResultSuccessMessage(char col, int row);//printing success message
	void printDeadEndMessage(char col, int row);//printing message when got in trap
	void printIncorrectInputMessage();//printing message when user chooses incorrect menu item
};

