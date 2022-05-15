#include "Move.h"  // include Move header 
#include "MovesCounter.h" //include Movescounter header

bool Move::neighbour(int rowStart, int colStart, int rowEnd, int colEnd, std::vector<std::vector<int>> possibleOptions)
                   //checking if first move is close to last one
{
    for (int i = 0; i < N; ++i)
        if ((rowStart + possibleOptions[0][i] == rowEnd) && (colStart + possibleOptions[1][i] == colEnd))
            // if rowStart and colStart is close to rowEnd and colEnd 
            return true;

    return false;
}

bool Move::isValid(std::vector<std::vector<int>>& table, int row, int col)
                 //checking if moving knight is possible on position row, col
{
    return row >= 0 && row < N && col >= 0 && col < N && !table[row][col]; 
    // return *true* if ALL conditions have been complied else return *false*
}

bool Move::nextMove(std::vector<std::vector<int>>& table, int& row, int& col, std::vector<std::vector<int>> possibleOptions)
                  // moving knight
{
    int minCount = 8; // minimum count of moves for the next move
    int index = 0; // index of next move that has minCount moves

    optimizeByWarnsdoffAlgorithm(table, index, minCount, row, col, possibleOptions); //find the best move

    if (minCount == 8)//if no ways to move knight
        {
            return false;
        }

    row += possibleOptions[0][index]; //move knight by row
    col += possibleOptions[1][index]; //move knight by col

    table[row][col] = MovesCounter::IncreaseCount(); //put number of move to pos

    return true;
}

void Move::optimizeByWarnsdoffAlgorithm(std::vector<std::vector<int>>& table, int& index, int& minCount, int rowStart, int colStart, std::vector<std::vector<int>> possibleOptions)
                                       //finding move that has minimum next moves
{
    for (int i = 0; i < N; ++i)
    {
        int rowNext = rowStart + possibleOptions[0][i];
        int colNext = colStart + possibleOptions[1][i];

        int c = 0; //count of possible moves of each j iteration

        if (isValid(table, rowNext, colNext))
        {
            for (int j = 0; j < N; ++j)
            {
                int rowNextNext = rowNext + possibleOptions[0][j];
                int colNextNext = colNext + possibleOptions[1][j];

                if (isValid(table, rowNextNext, colNextNext))
                {
                    ++c;
                }
            }

            if (c < minCount) //checking if current minCount value less than previous
            {
                minCount = c;
                index = i;
            }
        }
    }
}

