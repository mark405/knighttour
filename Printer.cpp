#include "Printer.h"
#include <iostream>
#include <iomanip>

#define N 8

void Printer::printTable(std::vector<std::vector<int>>& table)//printing matrix
{
    std::cout << std::setw(3);
    for (char ch = 'A'; ch != 'I'; ++ch) {
        std::cout << " " << std::setw(3) << std::left << ch;//printing column name 
    }
    std::cout << std::endl;
    //printing chess table with number of every 4 knight tour 
    for (int i = 0; i < N; ++i)
    {
        std::cout << i + 1 << " ";//printing row name
        for (int j = 0; j < N; ++j)
        {
            std::cout << "\033[1;47m"; //set white background for bold symbols
            if ((i + j) % 2) {//if  position is a multiple of 2
                std::cout << "\033[1;40m"; //set black background for bold symbols
            }

            if (!(table[i][j] % 4) && table[i][j])//if the number of tour on this position is a multiple of 4 and the knight wisited this position
            {
                std::cout << " " << std::setw(3) << std::left << table[i][j];//printing number of knight tour 
            }
            else
            {
                std::cout << " " << std::setw(3) << std::left << " ";//printing " "
            }
        }
        std::cout << "\033[0m\n"; //set default background
    }
    std::cout << std::endl;
}

void Printer::printResultErrorMessage(char col, int row)//printing error message
{
    //printing error message and starting position
     std::cout << "\nCan't return to starting position from " << col << row + 1 << std::endl;
}

void Printer::printResultSuccessMessage(char col, int row)//printing success message
{
    //printing success message and starting position
    std::cout << "\nSucces!Your starting position is " << col << row + 1 << std::endl;
}

void Printer::printIncorrectInputMessage()//printing message when got in trap
{
    std::cout << "\nIncorrect input." << std::endl;
}

void Printer::printDeadEndMessage(char col, int row)//printing message when user chooses incorrect menu item
{
    //printing message about trap and starting position
     std::cout << "\nGot in a trap! from " << col << row + 1 << std::endl;
}

