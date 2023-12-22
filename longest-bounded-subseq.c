/*
Problem: Longest Bounded SubSequence
Description
Given a sequence of positive integers a = a1, a2, . . ., an. A subsequence of a is defined to be a sequence of consecutive elements ai, ai+1, . . ., aj (1 <= i <= j <= n). The weight of a subsequence is the sum of its elements. Given a positive integer Q. A subsequence is said to be feasible if the weight is less than or equal to Q.
Find a feasible subsequence such that the number of elements of that subsequence is maximal.
Input

    Line 1: contains two positive integers n and Q (1 <= n <= 106, 1 <= Q <= 100000)
    Line 2: contains a1, a2, . . ., an (1 <= ai <= 10000).

Output

    Write the number of elements of the subsequence found, or write -1 if no such subsequence exists.

Example
Input
10 40
19 2 7 6 9 1 17 19 8 4
Output
5
*/
#include <stdio.h>

int longestFeasibleSubsequence(int arr[], int n, int Q)
{
    int start = 0, end = 0, sum = 0, maxLength = -1;

    while (end < n) {
        // Add the current element to the sum
        sum += arr[end];

        // If sum exceeds Q, move the start pointer
        while (sum > Q && start <= end) {
            sum -= arr[start];
            start++;
        }

        // Update the maximum length if this subsequence is feasible
        if (sum <= Q) {
            maxLength = (maxLength > (end - start + 1)) ? maxLength : (end - start + 1);
        }

        // Move to the next element
        end++;
    }

    return maxLength;
}

int main()
{
    int n, Q;
    scanf("%d %d", &n, &Q);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = longestFeasibleSubsequence(arr, n, Q);
    printf("%d\n", (result == -1) ? -1 : result);

    return 0;
}
