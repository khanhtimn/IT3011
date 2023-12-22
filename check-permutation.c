/*
Problem: Permu
Description
Given a sequence of n integers a1, a2, . . ., an. Check if the sequence if a permutation of 1, 2, . . ., n

Input

    Line 1: contains a positive integer n (1 <= n <= 1000000)
    Line 2: contains n integer a1, a2, . . ., an (-2147483647 <= ai <= 2147483647)


Output
Write 1 if the given sequence is a permutation of 1, 2, ..., n, and wirte 0, otherwise.

Example
Input
4
1 3 4 2
Output
1


Input
5
2 3 4 1 3
Output
0

Input
5
1 4 8 5 4
Output
0
*/
#include <stdio.h>

int main()
{
    int n;
    scanf("%d", &n);

    int isPermutation = 1; // Assume it's a permutation initially
    int count[n + 1]; // An array to count occurrences of numbers

    // Initialize count array to all zeros
    for (int i = 1; i <= n; i++) {
        count[i] = 0;
    }

    // Read the sequence and update the count array
    for (int i = 0; i < n; i++) {
        int num;
        scanf("%d", &num);

        if (num < 1 || num > n) {
            isPermutation = 0; // If the number is out of range, it can't be a permutation
        } else {
            count[num]++;
            if (count[num] > 1) {
                isPermutation = 0; // If a number is repeated, it can't be a permutation
            }
        }
    }

    // Check if the count array contains all 1s
    for (int i = 1; i <= n; i++) {
        if (count[i] != 1) {
            isPermutation = 0; // If any count is not 1, it can't be a permutation
            break;
        }
    }

    // Output the result
    printf("%d\n", isPermutation);

    return 0;
}
