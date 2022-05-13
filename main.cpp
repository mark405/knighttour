#include <iostream>
#include "Printer.h"
#include "Move.h"
#include "ClosedTourAlgorithm.h"
#include "MovesCounter.h"
#include "Menu.h"

void menu();

int main()
{
    srand(time(NULL));

    menu();

    return 0;
}

void menu()
{
    Menu menu;
    Printer printer;
    Move move;
    ClosedTourAlgorithm closedTourAlgorithm(printer, move);

    int choice, row, col;
    char colChar;
    bool status = true;

    while (status)
    {
        MovesCounter::ResetCount();

        menu.PrintOptions();

        choice = menu.ChooseDestiny();

        STATUS RESULT;

        switch (choice)
        {
        case 1:
            row = 0;
            col = 0;

            menu.EnterPositions(row, col, colChar);

            RESULT = closedTourAlgorithm.findClosedTour(--row, --col);

            if (RESULT == FAILURE)
            {
                printer.printResultErrorMessage(colChar, row);
            }
            else if(RESULT == TRAP)
            {
                printer.printDeadEndMessage(colChar, row);
            } else if (RESULT == SUCCESS)
            {
                printer.printResultSuccessMessage(colChar, row);
            }
            break;
        case 2:
            row = rand() % N + 1;
            col = rand() % N + 1;

            colChar = col + '0' + 16;

            RESULT = closedTourAlgorithm.findClosedTour(--row, --col);

            if (RESULT == FAILURE)
            {
                printer.printResultErrorMessage(colChar, row);
            }
            else if(RESULT == TRAP)
            {
                printer.printDeadEndMessage(colChar, row);
            }
            else if (RESULT == SUCCESS)
            {
                printer.printResultSuccessMessage(colChar, row);
            }
            break;

        case 3:
            status = false;
            break;

        default:
            printer.printIncorrectInputMessage();
        }
    }
}
