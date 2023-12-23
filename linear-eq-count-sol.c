/*
Problem: Count solutions to an integer linear equation
Description
Given a positive integer n and n positive integers a1, a2, ..., an. Compute the number of positive integer solutions to the equation:
                         a1x1 + a2x2 + .. + anxn = m

Input
First line 1: n and M
Second line: a1, a2, ... an.
Output
   The number of positive integer solutions
Example:
Input
3 5
1 1 1
Output
6
*/
#include <stdio.h>

int countSolutions(int a[], int n, int M, int pos)
{
    if (M == 0 && pos == n) // Check if we have used all variables and the sum is M
        return 1;
    if (M <= 0 || pos == n) // Check if sum exceeds M or all variables are used
        return 0;

    int solutions = 0;
    for (int i = 1; i <= M; i++) {
        solutions += countSolutions(a, n, M - a[pos] * i, pos + 1);
    }

    return solutions;
}

int main()
{
    int n, M;
    scanf("%d %d", &n, &M);
    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("%d\n", countSolutions(a, n, M, 0));
    return 0;
}
