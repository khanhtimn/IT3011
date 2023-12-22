/*
Problem: k-subsequence weight equal to m
Description
Given a sequence of integers a1, a2, . . ., an. A k-subsequence is define to be a sequence of k consecutive elements: ai, ai+1, . . ., ai+k-1. The weight of a k-subsequence is the sum of its elements.
Given positive integers k and m. Compute the number Q of k-subsequences such that the weight is equal to m.
Input

    Line 1: contains 3 positive integers n, k, m (1 <= n <= 100000, 1 <= k <= n/2,  1 <= m <= 1000000)
    Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)

Output

    Write the value Q

Example
Input
6 3 9
3 2 4 3 2 1
Output
3
*/
#include <stdio.h>

int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);

    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int count = 0;
    int sum = 0;

    // Initialize the sum for the first k elements
    for (int i = 0; i < k; i++) {
        sum += a[i];
    }

    // Iterate through the sequence with a sliding window
    for (int i = 0; i <= n - k; i++) {
        if (sum == m) {
            count++;
        }

        // Update the sum for the next k elements using the sliding window
        sum -= a[i];
        if (i + k < n) {
            sum += a[i + k];
        }
    }

    printf("%d\n", count);
    return 0;
}
