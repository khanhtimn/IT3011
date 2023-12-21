/*Problem: Check Sudoku
Description
A matrix 9 x 9 is called a sudoku solution if it satisfies following constraints

    Each element is an integer from 1 to 9
    Elements on each row are distinct
    Elements on each column are distinct
    Elements on each sub-square 3x3 are distinct (the matrix is divided into 9 distinct subsquares of size 3x3)


Write a program that checks whether or not a given matrix is a sudoku solution
Input

    Line 1: contains a positive integer T which is the number of matrix 9x9
    Subsequent lines are blocks, each block contains a matrix 9x9 with the following format
    Line i (i = 1, 2, ..., 9) contains the ith line of the matrix


Output

    Contains T lines, each line i (i = 1, 2, ..., T) contains 1 if the ith matrix is a sudoku solution, and contains 0, otherwise


Example
Input
2
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 1 6 7 8 9 4 2
9 7 2 5 4 1 6 3 8
6 4 8 9 3 2 5 7 1
1 2 3 4 5 6 7 8 9
4 5 6 7 8 9 1 2 3
7 8 9 1 2 3 4 5 6
2 1 4 3 6 5 8 9 7
3 6 5 8 9 7 2 1 4
8 9 7 2 1 4 3 6 5
5 3 1 6 7 8 9 4 2
9 7 8 5 4 2 6 3 1
4 4 2 9 3 1 5 7 8

Output
1
0
*/

#include <stdbool.h>
#include <stdio.h>

#define SIZE 9

// Function to check if a 9x9 matrix is a valid Sudoku solution
bool isValidSudoku(int grid[SIZE][SIZE])
{
    bool rowChecker[SIZE][SIZE] = { 0 }, colChecker[SIZE][SIZE] = { 0 }, boxChecker[SIZE][SIZE] = { 0 };

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int num = grid[i][j];

            // Check if the number is within the valid range for Sudoku
            if (num < 1 || num > SIZE) {
                return false;
            }

            num--; // Adjusting 1-9 to 0-8 for indexing
            int boxIndex = (i / 3) * 3 + j / 3;

            if (rowChecker[i][num] || colChecker[j][num] || boxChecker[boxIndex][num]) {
                return false; // Duplicate found
            }

            rowChecker[i][num] = true;
            colChecker[j][num] = true;
            boxChecker[boxIndex][num] = true;
        }
    }

    return true;
}

int main()
{
    int T, grid[SIZE][SIZE];
    scanf("%d", &T);

    for (int t = 0; t < T; t++) {
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                scanf("%d", &grid[i][j]);
            }
        }

        printf("%d\n", isValidSudoku(grid) ? 1 : 0);
    }

    return 0;
}
