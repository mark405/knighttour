#include "Printer.h"
#include <iostream>
#include <iomanip>

#define N 8

void Printer::printTable(std::vector<std::vector<int>>& table)
{
    std::cout << "-------------------------------------------------\n";

    for (int i = 0; i < N; ++i)
    {
        std::cout << "|";

        for (int j = 0; j < N; ++j) 
        {
            if (table[i][j] % 4 == 0)
            {
                std::cout << "  " << std::setw(3) << std::left << table[i][j] << "|";
            }
            else if (table[i][j] % 4 != 0)
            {
                std::cout << "  " << std::setw(3) << std::left << 0 << "|";
            }
        }

        std::cout << "\n-------------------------------------------------\n";
    }
    std::cout << std::endl;
}

void Printer::printResultErrorMessage(int row, int col)
{
    std::string message = "\nCan't return to starting position from (" + std::to_string(row + 1) + ';' + std::to_string(col + 1) + ')';
    std::cout << message << std::endl;
}

void Printer::printResultSuccessMessage(int row, int col)
{
    std::string message = "\nSucces!Your starting position is (" + std::to_string(row + 1) + ';' + std::to_string(col + 1) + ')';
    std::cout << message << std::endl;
}

void Printer::printIncorrectInputMessage()
{
    std::cout << "\nIncorrect input." << std::endl;
}
