/*
Problem: Longest Increasing subsequence
Description
Given a sequence a of positive a1, a2, . . ., an. A subsequence of a is defined to be the sequence obtained by removing some elements. Find the subsequence of a such that the elements is in an increasing order and the number of elements of the subsequence is maximal.

Input

    Line 1: contains a positive integer n (1 <= n <= 10000)
    Line 2: contains n elements of the given sequence (1 <= ai <= 10000)

Output
The length of the subsequence found.

Example
Input
6
5 8 2 8 10 10

Output
3
*/
#include <stdio.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int main()
{
    int n;
    scanf("%d", &n);
    int arr[n];
    int lis[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        lis[i] = 1; // Initialize LIS values for all indexes as 1.
    }

    // Compute optimized LIS values in bottom-up manner.
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
            }
        }
    }

    // Find the maximum value in lis[]
    int maxLis = 0;
    for (int i = 0; i < n; i++) {
        maxLis = max(maxLis, lis[i]);
    }

    printf("%d\n", maxLis);
    return 0;
}
