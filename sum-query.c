/*
Problem: Sum query on array
Description
Given a sequence of integers a1, a2, . . ., an. Perform a sequence of queries sum(i,j) which computes the sum ai + ai+1 + ... + aj.
Input

    Line 1: a positive integer n (1 <= n <= 1000000)
    Line 2: the sequence a1, a2, . . ., an (1 <= ai <= 200)
    Line 3: a positive integer K (1 <= K <= 1000000)
    Line i + 3 (i = 1, 2, ..., K): contains 2 integers i and j (1 <= i <= j <= n) represents the information about the ith query

Output
Line i (i = 1,...,K) writes the result of the ith query
Example
Input
5
10 3 9 6 2
6
2 5
2 4
2 3
2 4
1 4
2 3

Output
20
18
12
18
28
12
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, K, i, j;

    scanf("%d", &n);

    // Dynamically allocate memory for the sequence and prefix sum array
    int* sequence = (int*)malloc(n * sizeof(int));
    if (sequence == NULL) {
        // fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    long long* prefix_sum = (long long*)malloc((n + 1) * sizeof(long long));
    if (prefix_sum == NULL) {
        // fprintf(stderr, "Memory allocation failed\n");
        free(sequence); // Free already allocated memory
        return 1;
    }

    prefix_sum[0] = 0;
    for (i = 1; i <= n; i++) {
        scanf("%d", &sequence[i - 1]);
        prefix_sum[i] = prefix_sum[i - 1] + sequence[i - 1];
    }

    scanf("%d", &K);

    for (i = 0; i < K; i++) {
        scanf("%d %d", &j, &n);
        printf("%lld\n", prefix_sum[n] - prefix_sum[j - 1]);
    }

    // Free allocated memory
    free(sequence);
    free(prefix_sum);

    return 0;
}
