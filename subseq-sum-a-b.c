/*
Problem: Subset of a sequence sum is from A to B
Description
Given n distinct integers a1, a2,  . . ., an. Given two positive integers A and B. Compute the number Q of subsets of the given n integers such that the sum of its elements is greater or equal to A and less than or equal to B.
Input

    Line 1: contains n, A, B (4 <= n <= 20, 1 <= A <= B <= 100)
    Line 2: contains a1, a2, . . ., an ( 1 <= ai <= 50)

Output

    Write the value Q

Example
Input
5  5 10
9  4  10  3  7
Output
5
*/
#include <stdio.h>

int countSubsets(int arr[], int n, int A, int B)
{
    int count = 0;
    for (int i = 0; i < (1 << n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                sum += arr[j];
            }
        }
        if (sum >= A && sum <= B) {
            count++;
        }
    }
    return count;
}

int main()
{
    int n, A, B;
    scanf("%d %d %d", &n, &A, &B);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = countSubsets(arr, n, A, B);
    printf("%d\n", result);

    return 0;
}
