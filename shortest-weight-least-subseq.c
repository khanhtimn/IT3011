/*
Problem: Shortest weight at least subsequence
Description
Given a sequence of positive integers a = a1, a2, . . ., an. A subsequence of a is defined to be a sequence of consecutive elements ai, ai+1, . . ., aj (1 <= i <= j <= n). The weight of a subsequence is the sum of its elements. Given a positive integer Q. A subsequence is said to be feasible if the weight is greater than or equal to Q.
Find a feasible subsequence such that the number of elements of that subsequence is minimal.
Input

    Line 1: contains two positive integers n and Q (1 <= n <= 106, 1 <= Q <= 1000000)
    Line 2: contains a1, a2, . . ., an (1 <= ai <= 10000).

Output

    Write the number of elements of the subsequence found, or write -1 if no such subsequence exists.

Example
Input
6 20
2 2 5 6 5 7
Output
4
*/
#include <stdio.h>

int main()
{
    int n, Q;
    scanf("%d %d", &n, &Q);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int minLength = n + 1;
    int left = 0, right = 0;
    int sum = 0;
    int minLengthFound = 0;

    while (right < n) {
        sum += a[right];
        right++;

        while (sum >= Q) {
            minLength = (right - left) < minLength ? (right - left) : minLength;
            sum -= a[left];
            left++;
            minLengthFound = 1;
        }
    }

    if (minLengthFound) {
        printf("%d\n", minLength);
    } else {
        printf("-1\n");
    }

    return 0;
}
