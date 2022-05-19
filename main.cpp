#include <iostream>
#include "Printer.h"
#include "Move.h"
#include "ClosedTourAlgorithm.h"
#include "MovesCounter.h"
#include "Menu.h"

void menu();

int process()
{
    srand(time(NULL)); //for real randomisation

    process(); //starting proccess...

    return 0;
}

void process()
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
        MovesCounter::ResetCount(); //sets counter to zero

        menu.PrintOptions(); //starting

        choice = menu.ChooseDestiny();

        STATUS RESULT;//for status of func closedTourAlgorithm

        switch (choice)
        {
            case 1:
                row = 0;
                col = 0;

                menu.EnterPositions(row, col, colChar);//let input pos to user

                RESULT = closedTourAlgorithm.findClosedTour(--row, --col);

                colChar = toupper(colChar);

                if (RESULT == STATUS::FAILURE) //if an opened tour
                {
                    printer.printResultErrorMessage(colChar, row);
                }
                else if(RESULT == STATUS::TRAP) //if broken tour and have no end
                {
                    printer.printDeadEndMessage(colChar, row);
                } else if (RESULT == STATUS::SUCCESS) //if closed tour
                {
                    printer.printResultSuccessMessage(colChar, row);
                }
                std::cout << "Number of moves: " << MovesCounter::Getcount() << std::endl;
                break;
            case 2:
                row = rand() % N + 1; //1 - 8
                col = rand() % N + 1;

                colChar = col + '0' + 16; //coversion from int to char

                RESULT = closedTourAlgorithm.findClosedTour(--row, --col);

                if (RESULT == STATUS::FAILURE) //if an opened tour
                {
                    printer.printResultErrorMessage(colChar, row);
                }
                else if(RESULT == STATUS::TRAP) //if broken tour and have no end
                {
                    printer.printDeadEndMessage(colChar, row);
                }
                else if (RESULT == STATUS::SUCCESS) //if closed tour
                {
                    printer.printResultSuccessMessage(colChar, row);
                }
                std::cout << "Number of moves: " << MovesCounter::Getcount() << std::endl;
                break;

            case 3:
                status = false; //exit
                break;

            default:
                printer.printIncorrectInputMessage(); //if no correct options were choosed
        }
    }
}
