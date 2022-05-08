#include <iostream>
#include <vector> 
#include <iomanip> 
#include "Printer.h"
#include "Move.h"
#include "WarnsdoffAlgorithm.h"
#include "ClosedTourAlgorithm.h"
#include "MovesCounter.h"
#include "Menu.h"

void menu();

int main()
{
    srand(time(NULL));

    std::vector<std::vector<int>> table(N, std::vector<int>(N, 0));

    menu();

    return 0;
}

void menu()
{
    Menu menu;
    Printer printer;
    Move move;
    ClosedTourAlgorithm closedTourAlgorithm(&printer, &move);
    int choice, row, col;

    while (true)
    {
        MovesCounter::ResetCount();

        menu.PrintOptions();

        choice = menu.ChooseDestiny();

        switch (choice)
        {
        case 1:
            row = -1;
            col = -1;

            menu.EnterPositions(&row, &col);

            if (!closedTourAlgorithm.findClosedTour(--row, --col))
            {
                printer.printResultErrorMessage(row, col);
            }
            else
            {
                printer.printResultSuccessMessage(row, col);
            }
            break;

        case 2:
            row = rand() % N;
            col = rand() % N;

            if (!closedTourAlgorithm.findClosedTour(row, col))
            {
                printer.printResultErrorMessage(row, col);
            }
            else
            {
                printer.printResultSuccessMessage(row, col);
            }
            break;

        case 3:
            return;

        default:
            printer.printIncorrectInputMessage();
        }
    }
}
