/*
Problem: Max SubSequence
Description
Given an integers sequence a=(a1, a2,…, an). A subsequence of aa is defined to be ai, ai+1,…, aj. The weight of a subsequence is the sum of its elements. Find the subsequence having the highest weight.
Input

    Line 1 contains n (1≤n≤106)
    Line 2 contains a1,…,an (−500≤ai≤500)

Output
Write the weight of the highest subsequence found.
Example
input
10
3 -1 -3 5 2 5 0 -1 5 4
output
20
*/
#include <stdio.h>

int maxSubsequenceWeight(int n, int arr[])
{
    int max_sum = arr[0];
    int current_sum = arr[0];

    for (int i = 1; i < n; i++) {
        // Calculate the maximum sum ending at index i
        current_sum = (current_sum > 0) ? current_sum + arr[i] : arr[i];

        // Update the maximum sum if the current sum is greater
        if (current_sum > max_sum) {
            max_sum = current_sum;
        }
    }

    return max_sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = maxSubsequenceWeight(n, arr);
    printf("%d\n", result);

    return 0;
}
