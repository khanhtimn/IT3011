/*
Problem: k-subsequence bounded weight
Description
Given a sequence of integers a1, a2, . . ., an. A k-subsequence is define to be a sequence of k consecutive elements: ai, ai+1, . . ., ai+k-1. The weight of a k-subsequence is the sum of its elements.
Given positive integers k,  A, and B. Compute the number Q of k-subsequences such that the weight is greater or equal to A and less than or equal to B.
Input

    Line 1: contains 3 positive integers n, k, A, B (1 <= n <= 100000, 1 <= k <= n/2,  1 <= A, B <= 1000000)
    Line 2: contains a1, a2, . . ., an. (1 <= ai <= 100)

Output

    Write the value Q

Example
Input
5 3 6 18
2 2 8 8 3
Output
2
*/
#include <stdio.h>

int main()
{
    int n, k, A, B;
    scanf("%d %d %d %d", &n, &k, &A, &B);

    int sequence[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &sequence[i]);
    }

    long long int sum = 0;
    int count = 0;

    for (int i = 0; i < k; i++) {
        sum += sequence[i];
    }

    if (sum >= A && sum <= B) {
        count++;
    }

    for (int i = k; i < n; i++) {
        sum += sequence[i] - sequence[i - k];
        if (sum >= A && sum <= B) {
            count++;
        }
    }

    printf("%d\n", count);

    return 0;
}
