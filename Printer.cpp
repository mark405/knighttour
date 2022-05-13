#include "Printer.h"
#include <iostream>
#include <iomanip>

#define N 8

void Printer::printTable(std::vector<std::vector<int>>& table)
{
    std::cout << std::setw(3);
    for (char ch = 'A'; ch != 'I'; ++ch) {
        std::cout << " " << std::setw(3) << std::left << ch;
    }
    std::cout << std::endl;

    for (int i = 0; i < N; ++i)
    {
        std::cout << i + 1 << " ";
        for (int j = 0; j < N; ++j)
        {
            std::cout << "\033[1;47m"; //white bold bg
            if((i + j) % 2) {
                std::cout << "\033[1;40m"; //black bold bg
            }

            if (!(table[i][j] % 4) && table[i][j])
            {
                std::cout << " " << std::setw(3) << std::left << table[i][j];
            }
            else
            {
                std::cout << " " << std::setw(3) << std::left << " ";
            }
        }
        std::cout << "\033[0m\n"; //default background
    }
    std::cout << std::endl;
}

void Printer::printResultErrorMessage(char col, int row)
{
    std::cout << "\nCan't return to starting position from " << col << row + 1 << std::endl;
}

void Printer::printResultSuccessMessage(char col, int row)
{
    std::cout << "\nSucces!Your starting position is " << col << row + 1 << std::endl;
}

void Printer::printIncorrectInputMessage()
{
    std::cout << "\nIncorrect input." << std::endl;
}

void Printer::printDeadEndMessage(char col, int row)
{
    std::cout << "\nGot in a trap! from " << col << row + 1 << std::endl;
}
