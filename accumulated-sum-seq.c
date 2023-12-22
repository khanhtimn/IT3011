/*
Problem: Query Sum Sub-Sequence
Description
Given a sequence of integers a1, a2, . . ., an. Each query is represented by a pair of indices (i, j), we need to compute Q(i,j) = ai + ai+1 + . . . + aj.
Input

    Line 1: a positive integer n (1 <= n <= 100000)
    Line 2: a1, a2, . . ., an (1 <= ai <= 1000)
    Line 3: a positive integer K
    Line 3+k (k = 1, 2, ..., K): contains 2 integers i and j (1 <= i <= j <= n) which are indices of the kth query


Output

    Line k (k = 1,...,K): write the value of Q(i,j)


Example
Input
5
1 2 3 4 5
4
1 3
2 5
3 4
3 5

Output
6
14
7
12
*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int a[n];
    int cumSum[n + 1]; // Array to store cumulative sums
    cumSum[0] = 0;

    // Read the input array and compute cumulative sums
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cumSum[i + 1] = cumSum[i] + a[i];
    }

    int k;
    scanf("%d", &k);
    for (int q = 0; q < k; q++) {
        int i, j;
        scanf("%d %d", &i, &j);

        // Calculate the sum from index i to j using cumulative sums
        int sum = cumSum[j] - cumSum[i - 1];

        printf("%d\n", sum);
    }

    return 0;
}
