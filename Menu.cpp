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

    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        choice = -1;
    }

    return choice;
}

void Menu::EnterPositions(int &row, int &col, char &colChar)
{
    std::cout << "\nEnter positions:";
    do
    {
        std::cout << "\nLetter: ";
        std::cin >> colChar;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }

        std::cout << "Number: ";
        std::cin >> row;

        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }

        col = toupper(colChar) - '0' - 16;
    } while (row <= 0 || col <= 0 || row > N || col > N);
}

