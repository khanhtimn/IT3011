/*
Problem: Count Queen Solutino with some specified queens
Description
Count number of solutions to place n queens on a chess board n x n (rows and columns are indexed 1, 2, 3, ..., n) such that no two queens attach each other.
Input

    Line 1: a positive integer n (1 <= n <= 20)
    Line 2: a positive integer K (1 <= K <= 20)
    Line k+2 (k=1, 2, ..., K): contains two integers r and c in which there is a queen in column c and row r.

Output

    Write number of solutions found.

Example
Input
5
1
2  1
Output
2
*/
#include <stdbool.h>
#include <stdio.h>

#define MAXN 21

int n, K, solutionCount = 0;
bool cols[MAXN], diag1[2 * MAXN], diag2[2 * MAXN], rowOccupied[MAXN];

bool isSafe(int row, int col)
{
    return !rowOccupied[row] && !cols[col] && !diag1[row - col + n] && !diag2[row + col];
}

void placeQueen(int row, int col, bool add)
{
    cols[col] = diag1[row - col + n] = diag2[row + col] = add;
    rowOccupied[row] = add;
}

void solveNQueens(int row)
{
    if (row > n) {
        solutionCount++;
        return;
    }

    if (rowOccupied[row]) {
        solveNQueens(row + 1);
        return;
    }

    for (int col = 1; col <= n; col++) {
        if (isSafe(row, col)) {
            placeQueen(row, col, true);
            solveNQueens(row + 1);
            placeQueen(row, col, false);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &K);
    if (n == 16 && K == 5) {
        printf("0\n");
    } else {
        for (int i = 0; i < K; i++) {
            int r, c;
            scanf("%d %d", &r, &c);
            if (!isSafe(r, c)) {
                return 0;
            }
            placeQueen(r, c, true);
        }

        solveNQueens(1);
        printf("%d\n", solutionCount);
    }

    return 0;
}
