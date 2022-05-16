#include "Menu.h"// include Menu header 
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

    if (std::cin.fail()) {//if user input incorrect  data type
        std::cin.clear();//cleaning buffer
        std::cin.ignore(32767, '\n');
        choice = -1;
    }

    return choice;
}

void Menu::EnterPositions(int &row, int &col, char &colChar)//entering starting positions
{
    std::cout << "\nEnter positions:";
    //asking user for starting positions until  the possible  positions are entered
    do
    {
        std::cout << "\nLetter: ";
        std::cin >> colChar;

        if (std::cin.fail()) {//if user input incorrect  data type
            std::cin.clear();//cleaning buffer
            std::cin.ignore(32767, '\n');
        }

        std::cout << "Number: ";
        std::cin >> row;

        if(std::cin.fail()) {//if user input incorrect  data type
            std::cin.clear();//cleaning buffer
            std::cin.ignore(32767, '\n');
        }

        col = toupper(colChar) - '0' - 16;//convertation from char to int
    } while (row <= 0 || col <= 0 || row > N || col > N);
}

