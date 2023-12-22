/*
Problem: Linear Integer Equation - coefficent 1
Description
Given two integer n and M. Write a program that generates all ordered collection (X1, X2, ..., Xn) such that: X1 + X2 + . . . + Xn = M
Input

    Line 1: contains 2 integers n and M (2 <= n <= 10, 1 <= M <= 20)

Output

    Write in each line X1, X2, ..., Xn separated by a SPACE character

Example
Input
3  5
Output
1 1 3
1 2 2
1 3 1
2 1 2
2 2 1
3 1 1
*/
#include <stdio.h>

void printArray(int* a, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void generateCombinations(int n, int M, int* arr, int index, int currentSum)
{
    if (index == n) {
        if (currentSum == M) {
            printArray(arr, n);
        }
        return;
    }

    for (int i = 1; i <= M; i++) {
        arr[index] = i;
        generateCombinations(n, M, arr, index + 1, currentSum + i);
    }
}

int main()
{
    int n, M;
    scanf("%d %d", &n, &M);

    int arr[n];
    generateCombinations(n, M, arr, 0, 0);
    return 0;
}
