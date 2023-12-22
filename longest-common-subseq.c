/*
Problem: Longest Common Subsequence
Description
Denote X = X1, X2, …, Xn, a subsequence of X is created by removing some element from X.  Given two sequences X = X1, X2, …, Xn and Y = Y1, Y2, …, Ym. Find a common subsequence of X and Y such that the length is the longest.
Input

    Line 1: two positive integers n and m (1 <= n,m <= 10000)
    Line 2: n integers X1, X2, …, Xn
    Line 3:  m integers Y1, Y2, …, Ym

Output

    Length of the longest subsequence of X and Y

Example
Input
7 10
3 7 2 5 1 4 9
4 3 2 3 6 1 5 4 9 7
Output
5
*/
#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int longestCommonSubsequence(int X[], int Y[], int n, int m)
{
    int dp[m + 1];

    for (int i = 0; i <= n; i++) {
        int prev = 0; // Store the value of dp[i-1][j-1]
        for (int j = 0; j <= m; j++) {
            int temp = dp[j];
            if (i == 0 || j == 0)
                dp[j] = 0;
            else if (X[i - 1] == Y[j - 1])
                dp[j] = prev + 1;
            else
                dp[j] = max(dp[j], dp[j - 1]);
            prev = temp;
        }
    }

    return dp[m];
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    int X[n], Y[m];

    for (int i = 0; i < n; i++) {
        scanf("%d", &X[i]);
    }

    for (int i = 0; i < m; i++) {
        scanf("%d", &Y[i]);
    }

    int result = longestCommonSubsequence(X, Y, n, m);
    printf("%d\n", result);

    return 0;
}
