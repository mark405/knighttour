#include "ClosedTourAlgorithm.h"
#include "MovesCounter.h"


STATUS ClosedTourAlgorithm::findClosedTour(int& rowStart, int& colStart)
{
    TimerChecker timer;
    
    std::vector<std::vector<int>> table(N, std::vector<int>(N, 0)); //matrix with zero values
    std::vector<std::vector<int>> possibleOptions
    {
            {-2, 1,  2, 2,  -1, -1, -2, 1},
            {-1, -2, 1, -1, 2,  -2, 1,  2}
    };


    int row = rowStart, col = colStart;

    table[rowStart][colStart] = MovesCounter::IncreaseCount(); //put value of 1 to start position


    while (MovesCounter::Getcount() != 64)
    {
        if (!_move.nextMove(table, row, col, possibleOptions)) //if got lost or didnt find    
        {
            _printer.printTable(table);
            return TRAP; 
            //            return false;
        }
    }

    _printer.printTable(table);

    return _move.neighbour(rowStart, colStart, row, col, possibleOptions) ? SUCCESS : FAILURE; //if neighbour
}

