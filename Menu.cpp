#include "Menu.h"
#include <iostream>

void Menu::PrintOptions()
{
    std::cout << "\n1.Enter positions\n";
    std::cout << "2.Random positions\n";
    std::cout << "3.Exit\n";
}

int Menu::ChooseDestiny()
{
    int choice; 

    std::cout << "\nChoose your destiny:\n";
    std::cin >> choice;

    return choice;
}

void Menu::EnterPositions(int& row, int& col)
{ 
    std::cout << "\nEnter positions:";
    do
    {
        std::cout << "\nRow: ";
        std::cin >> row;     
        std::cout << "Col: ";  //comment
        std::cin >> col;
    } while (row <= 0 || col <= 0 || row > N || col > N);
}


