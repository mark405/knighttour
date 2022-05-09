#include "WarnsdoffAlgorithm.h"

void WarnsdoffAlgorithm::optimizeByWarnsdoffAlgorithm(std::vector<std::vector<int>>& table, int& index,
    int& minCount, int rowStart, int colStart, std::vector<std::vector<int>> possibleOptions)
{
    Move move;

    for (int i = 0; i < N; ++i) 
    {
        int rowNext = rowStart + possibleOptions[0][i];
        int colNext = colStart + possibleOptions[1][i];
        int c = 0;//count of possible moves of each j iteration

        if (move.isValid(table, rowNext, colNext)) 
        {
            for (int j = 0; j < N; ++j) 
            {
                int rowNextNext = rowNext + possibleOptions[0][j];
                int colNextNext = colNext + possibleOptions[1][j];

                if (move.isValid(table, rowNextNext, colNextNext)) 
                {
                    ++c;
                }
            }

            if (c < minCount) //checking if current miCount value less than previous
            { 
                minCount = c;
                index = i;
            }
        }
    }
}

