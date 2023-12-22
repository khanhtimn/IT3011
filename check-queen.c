/*
Problem: Check Queen solution
Description
Given a chess board N x N on which there are N being placed in N different cells.
Write a program that check if there are two queen, that attacks each other.

A board is represented by a NxN matrix A in which A[i,j] = 1 if there is a queen placed in cell (i,j), and A[i,j] = 0, otherwise.
Input

    Line 1: contains a positive integer T which is the number of test-cases (1 <= T <= 100)
    T following block, each block is the input of a test-case with the format:
    Line 1: contains a positive integer N (1 <= N <= 100)
    Line i+1 (i = 1, 2, . . ., N): contains the ith row of the matrix A

Output

    In each line t (t = 1, 2, ..., T), write 1 if in the test-case t, there are no two queen that attack each other, and write 0, otherwise

Example
Input
2
4
0 1 0 0
0 0 0 1
1 0 0 0
0 0 1 0
4
0 1 0 0
0 0 0 0
1 0 0 1
0 0 1 0
Output
1
0
*/
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// Check if any two queens are in the same column
bool checkColumns(int** board, int N)
{
    for (int col = 0; col < N; col++) {
        int queenCount = 0;
        for (int row = 0; row < N; row++) {
            queenCount += board[row][col];
            if (queenCount > 1)
                return false; // More than one queen in a column
        }
    }
    return true;
}

// Check diagonal conflicts
bool checkDiagonals(int** board, int N)
{
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col]) {
                // Check diagonals
                for (int i = 1; i < N; i++) {
                    if ((row + i < N && col + i < N && board[row + i][col + i]) || (row - i >= 0 && col - i >= 0 && board[row - i][col - i]) || (row + i < N && col - i >= 0 && board[row + i][col - i]) || (row - i >= 0 && col + i < N && board[row - i][col + i])) {
                        return false; // Found another queen on a diagonal
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    int T;
    scanf("%d", &T);

    while (T--) {
        int N;
        scanf("%d", &N);

        int** board = (int**)malloc(N * sizeof(int*));
        for (int i = 0; i < N; i++) {
            board[i] = (int*)malloc(N * sizeof(int));
            for (int j = 0; j < N; j++) {
                scanf("%d", &board[i][j]);
            }
        }

        // Check for conflicts
        bool safe = checkColumns(board, N) && checkDiagonals(board, N);

        printf("%d\n", safe ? 1 : 0);

        // Free memory
        for (int i = 0; i < N; i++) {
            free(board[i]);
        }
        free(board);
    }

    return 0;
}
/*
 * Failed some test-cases
 */
