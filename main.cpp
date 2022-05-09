#include <iostream>
#include <vector> 
#include <iomanip> 
#include "Printer.h"
#include "Move.h"
#include "ClosedTourAlgorithm.h"
#include "MovesCounter.h"
#include "Menu.h"
#include "TimerChecker.h"

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
    ClosedTourAlgorithm closedTourAlgorithm(printer, move);

    int choice, row, col;
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

            menu.EnterPositions(row, col);

            RESULT = closedTourAlgorithm.findClosedTour(--row, --col);

            if (RESULT == FAILURE)
            {
                printer.printResultErrorMessage(row, col);
            }
            else if (RESULT == TRAP)
            {
                printer.printDeadEndMessage(row, col);
            }
            else if (RESULT == SUCCESS)
            {
                printer.printResultSuccessMessage(row, col);
            }
            break;

        case 2:
            row = rand() % N + 1;
            col = rand() % N + 1;

            RESULT = closedTourAlgorithm.findClosedTour(--row, --col);

            if (RESULT == FAILURE)
            {
                printer.printResultErrorMessage(row, col);
            }
            else if (RESULT == TRAP)
            {
                printer.printDeadEndMessage(row, col);
            }
            else if (RESULT == SUCCESS)
            {
                printer.printResultSuccessMessage(row, col);
            }
            break;

        case 3:
            status = false;
            break;

        default:
            printer.printIncorrectInputMessage();
        }
        
        std::cout << "Number of moves: " << MovesCounter::Getcount() << std::endl;
    }
}

