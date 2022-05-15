#include "Menu.h"
#include <iostream>

void Menu::PrintOptions()//printing menu
{
    std::cout << "\n1.Enter positions\n";
    std::cout << "2.Random positions\n";
    std::cout << "3.Exit\n";
}

int Menu::ChooseDestiny()//choosing of action
{
    int choice;

    std::cout << "\nChoose your destiny:\n";
    std::cin >> choice;

    return choice;
}

void Menu::EnterPositions(int& row, int& col)//entering starting positions
{
    std::cout << "\nEnter positions:";
    do //asking user for starting positions until  the possible  positions are entered
    {
        std::cout << "\nRow: ";
        std::cin >> row;
        std::cout << "Col: ";
        std::cin >> col;
    } while (row <= 0 || col <= 0 || row > N || col > N);
}


