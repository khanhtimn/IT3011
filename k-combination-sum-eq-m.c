/*
Problem: K-combination sum is e qual to m
Description
Given a sequence of integers a1, a2, . . ., an.  Given positive integers k and m. Compute the number Q of ways to select k elements from the sequence such that the sum of selected elements is equal to m.
Input

    Line 1: contains 3 positive integers n, k, m (1 <= n <= 20, 1 <= k <= n/2,  1 <= m <= 1000)
    Line 2: contains a1, a2, . . ., an. (1 <= ai <= 100)

Output

    Write the value Q

Example
Input
5 3 10
1 2 3 4 5
Output
2
*/
#include <stdio.h>

int countCombinations(int arr[], int n, int k, int m)
{
    int dp[k + 1][m + 1];
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= m; j++) {
            dp[i][j] = 0;
        }
    }

    dp[0][0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = k; j > 0; j--) {
            for (int s = m; s >= arr[i]; s--) {
                dp[j][s] += dp[j - 1][s - arr[i]];
            }
        }
    }

    return dp[k][m];
}

int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = countCombinations(arr, n, k, m);
    printf("%d\n", result);

    return 0;
}
