#include "Move.h"
#include "WarnsdoffAlgorithm.h" 
#include "MovesCounter.h"

bool Move::neighbour(int rowStart, int colStart, int rowEnd, int colEnd, std::vector<std::vector<int>> possibleOptions)
{
    for (int i = 0; i < N; ++i)
        if ((rowStart + possibleOptions[0][i] == rowEnd) && (colStart + possibleOptions[1][i] == colEnd))
            return true;

    return false;
}

bool Move::isValid(std::vector<std::vector<int>>& table, int row, int col)
{
    return row >= 0 && row < N&& col >= 0 && col < N && !table[row][col];
}

bool Move::nextMove(std::vector<std::vector<int>>& table, int& row, int& col, std::vector<std::vector<int>> possibleOptions)
{
    WarnsdoffAlgorithm algorithm;
    int minCount = 8;
    int index = 0;

    algorithm.optimizeByWarnsdoffAlgorithm(table, index, minCount, row, col, possibleOptions); //find the best move

    if (minCount == 8)//if no ways to move knight
        {
            return false;
        }

    row += possibleOptions[0][index]; //move knight by row
    col += possibleOptions[1][index]; //move knight by col

    table[row][col] = MovesCounter::IncreaseCount(); //put number of move to pos

    return true;
}

