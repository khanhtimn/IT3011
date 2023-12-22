/*
Problem: Chapter2_QueenArrangment_VINHLT
Description
Xếp N quân hậu vào một bàn cờ sao cho không có 2 quân hậu nào "ăn nhau" (cùng hàng, cùng cột, cùng đường chéo).
Đầu vào: Số nguyên N
Đầu ra gồm nhiều hàng, mỗi hàng là một dãy số có ý nghĩa là giá trị hàng của các quân hậu từ cột 1 đến cột N.
 */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void printSolution(int* board, int N)
{
    for (int i = 0; i < N; i++) {
        printf("%d", board[i] + 1);
    }
    printf("\n");
}

bool isSafe(int* board, int row, int col, int N)
{
    for (int i = 0; i < col; i++) {
        if (board[i] == row || abs(board[i] - row) == abs(i - col))
            return false;
    }
    return true;
}

void solveNQUtil(int* board, int col, int N)
{
    if (col == N) {
        printSolution(board, N);
        return;
    }

    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col, N)) {
            board[col] = i;
            solveNQUtil(board, col + 1, N);
        }
    }
}

void solveNQ(int N)
{
    int* board = (int*)malloc(N * sizeof(int));

    if (board == NULL) {
        printf("Memory allocation failed");
        return;
    }

    solveNQUtil(board, 0, N);
    free(board);
}

int main()
{
    int N;
    printf("Enter the number of queens: ");
    scanf("%d", &N);
    solveNQ(N);
    return 0;
}
