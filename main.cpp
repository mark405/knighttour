#include <iostream>
#include <vector>
#include <iomanip>

#define N 8

const std::vector<std::vector<int>> possibleOptions{
        {1, 1,  2, 2,  -1, -1, -2, -2},
        {2, -2, 1, -1, 2,  -2, 1,  -1}
};

int count = 0;

void printTable(std::vector<std::vector<int>> &table); //printing matrix
bool neighbour(int rowStart, int colStart, int rowEnd, int colEnd); //checking if first move is close to last one
bool isValid(std::vector<std::vector<int>> &table, int row, int col); //checking if moving knight is possible on position row, col
bool nextMove(std::vector<std::vector<int>> &table, int &row, int &col); // moving knight
bool findClosedTour(); //checking if the algorithm found closed tour
void optimizeByWarnsdoffAlgorithm(std::vector<std::vector<int>> &table, int &index, int &minCount, int rowStart, int colStart); //finding move that has minimum next moves


int main() {
    srand(time(NULL));

    std::vector<std::vector<int>> table(N, std::vector<int> (N, 0));


    for(;;) {
        if(findClosedTour()) {
            break;
        }
        count = 0;
    }

    return 0;
}


void printTable(std::vector<std::vector<int>> &table) {
    std::cout << "-------------------------------------------------\n";
    for (int i = 0; i < N; ++i) {
        std::cout << "|";
        for (int j = 0; j < N; ++j) {
            std::cout << "  " << std::setw(3) << std::left << table[i][j] << "|" ;
        }
        std::cout << "\n-------------------------------------------------\n";
    }
    std::cout << std::endl;
}


bool neighbour(const int rowStart, const int colStart, const int rowEnd, const int colEnd) {
    for (int i = 0; i < N; ++i)
        if ((rowStart + possibleOptions[0][i] == rowEnd) && (colStart + possibleOptions[1][i] == colEnd))
            return true;

    return false;
}


bool isValid(std::vector<std::vector<int>> &table, const int row, const int col) {
    return row >= 0 && row < N && col >= 0 && col < N && !table[row][col];
}


bool nextMove(std::vector<std::vector<int>> &table, int &row, int &col) {


    int minCount = 8;
    int index = 0;

    optimizeByWarnsdoffAlgorithm(table, index, minCount, row, col); //find the best move

    if(minCount == 8) { //if no ways to move knight
        return false;
    }

    row += possibleOptions[0][index]; //move knight by row
    col += possibleOptions[1][index]; //move knight by col

    table[row][col] = ++count; //put number of move to pos

    return true;
}


bool findClosedTour() {

    std::vector<std::vector<int>> table(N, std::vector<int> (N, 0)); //matrix with zero values

    int rowStart = rand() % N; //random start position
    int colStart = rand() % N;

    int row = rowStart, col = colStart;

    table[rowStart][colStart] = ++count; //put value of 1 to start position


    while(count != 64) {
        if(!nextMove(table, row, col)) { //if got lost or didnt find
            return false;
        }
    }

    printTable(table);

    return neighbour(rowStart, colStart, row, col); //if neighbour
}


void optimizeByWarnsdoffAlgorithm(std::vector<std::vector<int>> &table, int &index, int &minCount, const int rowStart, const int colStart) {
    for (int i = 0; i < N; ++i) {
        int rowNext = rowStart + possibleOptions[0][i];
        int colNext = colStart + possibleOptions[1][i];
        int c = 0;//count of possible moves of each j iteration
        if(isValid(table, rowNext, colNext)) {
            for (int j = 0; j < N; ++j) {
                int rowNextNext = rowNext + possibleOptions[0][j];
                int colNextNext = colNext + possibleOptions[1][j];
                if (isValid(table, rowNextNext, colNextNext)) {
                    ++c;
                }
            }
            if(c < minCount) { //checking if current miCount value less than previous
                minCount = c;
                index = i;
            }
        }
    }
}

