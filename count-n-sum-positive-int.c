/*
Problem: Count the number of ways to represent n as the sum of positive integers
Description
Given a positive integer n. Write a program that computes the number Q of ways to represent n as the sum of positive integers
Input

    Line 1: a positive integer n (1 <= n <= 50)

Output

    Write the value Q mod 109+7

Example
Input
6
Output
11
*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int ways[n + 1];
    ways[0] = 1; // There is one way to make 0

    // Initialize all ways to 0
    for (int i = 1; i <= n; i++) {
        ways[i] = 0;
    }

    // Build the table ways[] in a bottom-up manner
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            ways[j] += ways[j - i];
        }
    }

    printf("%d\n", ways[n]);

    return 0;
}
