#include <iostream>

using namespace std;



const int N = 9;



void printGrid(int grid[N][N]) {

    for (int row = 0; row < N; row++) {

        for (int col = 0; col < N; col++) {

            cout << grid[row][col] << " ";

        }

        cout << endl;

    }

}



bool findEmptyLocation(int grid[N][N], int& row, int& col) {

    for (row = 0; row < N; row++) {

        for (col = 0; col < N; col++) {

            if (grid[row][col] == 0) {

                return true;

            }

        }

    }

    return false;

}



bool usedInRow(int grid[N][N], int row, int num) {

    for (int col = 0; col < N; col++) {

        if (grid[row][col] == num) {

            return true;

        }

    }

    return false;

}



bool usedInCol(int grid[N][N], int col, int num) {

    for (int row = 0; row < N; row++) {

        if (grid[row][col] == num) {

            return true;

        }

    }

    return false;

}



bool usedInBox(int grid[N][N], int boxStartRow, int boxStartCol, int num) {

    for (int row = 0; row < 3; row++) {

        for (int col = 0; col < 3; col++) {

            if (grid[row + boxStartRow][col + boxStartCol] == num) {

                return true;

            }

        }

    }

    return false;

}



bool isSafe(int grid[N][N], int row, int col, int num) {

    return !usedInRow(grid, row, num) &&

           !usedInCol(grid, col, num) &&

           !usedInBox(grid, row - row % 3, col - col % 3, num);

}



bool solveSudoku(int grid[N][N]) {

    int row, col;



    if (!findEmptyLocation(grid, row, col)) {

        return true; // Puzzle solved

    }



    for (int num = 1; num <= 9; num++) {

        if (isSafe(grid, row, col, num)) {

            grid[row][col] = num;



            if (solveSudoku(grid)) {

                return true;

            }



            grid[row][col] = 0; // Backtrack

        }

    }



    return false; // No solution found

}



int main() {

    int grid[N][N] = {

        {2, 0, 9, 0, 0, 0, 6, 0, 0},

        {0, 4, 0, 8, 7, 0, 0, 1, 2},

        {8, 0, 0, 0, 1, 9, 0, 4, 0},

        {0, 3, 0, 7, 0, 0, 8, 0, 1},

        {0, 6, 5, 0, 0, 8, 0, 3, 0},

        {1, 0, 0, 0, 3, 0, 0, 0, 7},

        {0, 0, 0, 6, 5, 0, 7, 0, 9},

        {6, 0, 4, 0, 0, 0, 0, 2, 0},

        {0, 8, 0, 3, 0, 1, 4, 5, 0}

    };



    if (solveSudoku(grid)) {

        cout << "Sudoku puzzle solved successfully:" << endl;

        printGrid(grid);

    } else {

        cout << "No solution exists." << endl;

    }



    return 0;
}