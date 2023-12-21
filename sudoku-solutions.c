/*
Problem: Count number of sudoku solutions
Description
Write a program to compute the number of sudoku solutions (fill the zero elements of a given partial sudoku table)
Fill numbers from 1, 2, 3, .., 9 to 9 x 9 table so that:

    Numbers of each row are distinct
    Numbers of each column are distinct
    Numbers on each sub-square 3 x 3 are distinct

Input

    Each line i (i = 1, 2, ..., 9) contains elements of the ith row of the Sudoku table: elements are numbers from 0 to 9 (value 0 means the empty cell of the table)

Output

    Write the number of solutions found


Example
Input
0 0 3 4 0 0 0 8 9
0 0 6 7 8 9 0 2 3
0 8 0 0 2 3 4 5 6
0 0 4 0 6 5 0 9 7
0 6 0 0 9 0 0 1 4
0 0 7 2 0 4 3 6 5
0 3 0 6 0 2 0 7 8
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
Output
64
*/

#include <stdbool.h>
#include <stdio.h>

#define SIZE 9

// Function prototypes
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num);
bool solveSudoku(int grid[SIZE][SIZE], int row, int col, int* solutionCount);

int main()
{
    int grid[SIZE][SIZE];
    int solutionCount = 0;

    // Reading the input grid
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            scanf("%d", &grid[i][j]);
        }
    }

    // Solving the Sudoku
    solveSudoku(grid, 0, 0, &solutionCount);

    // Output the number of solutions
    printf("%d\n", solutionCount);

    return 0;
}

// Function to check if a number can be placed in the given cell
bool isSafe(int grid[SIZE][SIZE], int row, int col, int num)
{
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Backtracking function to solve the Sudoku
bool solveSudoku(int grid[SIZE][SIZE], int row, int col, int* solutionCount)
{
    if (row == SIZE - 1 && col == SIZE) {
        (*solutionCount)++;
        return false; // Return false to continue finding more solutions
    }

    if (col == SIZE) {
        row++;
        col = 0;
    }

    if (grid[row][col] > 0) {
        return solveSudoku(grid, row, col + 1, solutionCount);
    }

    for (int num = 1; num <= SIZE; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid, row, col + 1, solutionCount)) {
                return true;
            }

            grid[row][col] = 0;
        }
    }

    return false;
}
