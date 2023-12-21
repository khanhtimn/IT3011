/*
Problem: Compute C_k_n
Description
Given two positive integers k and n. Compute C(k,n) which is the number of ways to select k objects from a given set of n objects.
Input

    Line 1: two positive integers k and n (1 <= k,n <= 999)

Output
Write te value C(k,n) modulo 109+7.
Example
Input
3  5
Output
10
*/
#include <stdio.h>

int main(void)
{
    int k, n;
    int i, j;
    int c[1000][1000];
    scanf("%d%d", &k, &n);
    for (i = 0; i <= n; i++) {
        c[i][0] = 1;
        c[i][i] = 1;
    }
    for (i = 2; i <= n; i++) {
        for (j = 1; j <= i - 1; j++) {
            c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % 1000000007;
        }
    }
    printf("%d\n", c[n][k]);
    return 0;
}
