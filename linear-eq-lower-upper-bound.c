/*
Problem: Linear equation with Lower and upper bound constraints on variables
Description
Write a program that computes the number of integer solutions to the following equation: a1X1 + a2X2 + . . . + anXn = m such that Li <= Xi <= Ui, (i = 1, 2, ..., n)
Input

    Line 1: n and m (1 <= n <= 10, 1 <= m <= 50)
    Line 2: a1, a2, ..., an (1 <= ai <= 100)
    Line i+2 (i = 1, ..., n): contains Li and Ui (1 <= Li <= Ui <= 100)

Output
Example
Input
4 11
1 1 1 1
3 7
2 6
4 7
1 10

Output
4
*/
#include <stdio.h>
#include <string.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int a[n], L[n], U[n];

    // Reading coefficients
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // Reading lower and upper bounds
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &L[i], &U[i]);
    }

    int dp[n + 1][m + 1];
    memset(dp, 0, sizeof(dp));

    dp[0][0] = 1; // Base case

    // Bottom-Up DP computation
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = L[i - 1]; k <= U[i - 1]; k++) {
                if (j >= a[i - 1] * k) {
                    dp[i][j] += dp[i - 1][j - a[i - 1] * k];
                }
            }
        }
    }

    printf("%d\n", dp[n][m]);

    return 0;
}
