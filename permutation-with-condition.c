#include <stdio.h>
/*
Problem: Permutation with condition
Description
Let the set N = {1, 2, 3, ..., n}. Each n-element permutation of the set N is
represented by the array {a[1], a[2],..., a[n]}. An n-element permutation of the
set N is perfect if each element a[i] (with i = 1, 2, .., n) in the permutation
satisfies one of the following two conditions:
1) a[i] is divisible by i;
2)  i is divisible by a[i].
Input: a positive integer n (1 <= n <= 15).
Output: Number of perfect permutations including n elements created from the set N = {1, 2,
..., n}.
Example 1:
Input:
1
Output:
1
Example 2:
Input:
5
Output:
10
*/

int countPerfectPermutations(int pos, int n, int used[], int count)
{
    if (pos > n) {
        return count + 1;
    }

    for (int i = 1; i <= n; i++) {
        if (!used[i] && (pos % i == 0 || i % pos == 0)) {
            used[i] = 1;
            count = countPerfectPermutations(pos + 1, n, used, count);
            used[i] = 0; // Backtrack
        }
    }

    return count;
}

int main(void)
{
    int n;
    scanf("%d", &n);
    if (n > 15 || n <= 0) {
        return 0;
    }
    int used[n + 1];
    for (int i = 0; i <= n; i++) {
        used[i] = 0;
    }

    int count = countPerfectPermutations(1, n, used, 0);
    printf("%d\n", count);
    return 0;
}
