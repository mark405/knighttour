#include "ClosedTourAlgorithm.h"
#include "MovesCounter.h"

ClosedTourAlgorithm::ClosedTourAlgorithm(Printer *printer, Move *move)
{
    _printer = printer;  
    _move = move;          
}

bool ClosedTourAlgorithm::findClosedTour(int& rowStart, int& colStart)
{
    std::vector<std::vector<int>> table(N, std::vector<int>(N, 0)); //matrix with zero values

    int row = rowStart, col = colStart;

    table[rowStart][colStart] = MovesCounter::IncreaseCount(); //put value of 1 to start position

    while (MovesCounter::Getcount() != 64) 
    {
        if (!_move->nextMove(table, row, col)) //if got lost or didnt find
        { 
            return false;
        }
    }

    _printer->printTable(table);

    return _move->neighbour(rowStart, colStart, row, col); //if neighbour
}

