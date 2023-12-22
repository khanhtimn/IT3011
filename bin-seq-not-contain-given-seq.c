/*
Problem: Binary sequences do not contain another given binary sequence
Description
Given a binary sequence s and a positive integer n. Count the number Q of binary sequences of length n that does not contain s as a substring.
Input

    Line 1: contains n (1 <= n <= 20)
    Line 2: contains s (the length of s varies from 1 to 5)

Output
Write the value Q

Example
Input
3
10

Output
4
*/

#include <stdio.h>
#include <string.h>

int nextState(char* s, int state, char nextChar)
{
    int len_s = strlen(s), j;
    if (s[state] == nextChar) {
        return state + 1;
    }
    for (j = state; j > 0; j--) {
        if (s[j - 1] == nextChar) {
            int i;
            for (i = 0; i < j - 1; i++) {
                if (s[i] != s[state - j + 1 + i]) {
                    break;
                }
            }
            if (i == j - 1)
                return j;
        }
    }
    return 0;
}

int main()
{
    int n;
    char s[6];
    scanf("%d %s", &n, s);

    int len_s = strlen(s);
    long long dp[n + 1][len_s + 1];
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1; // Base case

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < len_s; j++) {
            // Append '0' and '1' and update states
            dp[i][nextState(s, j, '0')] += dp[i - 1][j];
            dp[i][nextState(s, j, '1')] += dp[i - 1][j];
        }
    }

    long long result = 0;
    for (int j = 0; j < len_s; j++) {
        result += dp[n][j];
    }

    printf("%lld\n", result);
    return 0;
}
