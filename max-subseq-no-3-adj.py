"""
Problem: Max Subsequence No 3 adjacent elements selected
Description
Given a sequence of positive integers a1, a2,  . . ., an. Select the subset of elements such that the sum is maximal and no 3 adjacent elements are selected.
Input

    Line 1: contains a positive integer n (1 <= n <= 100000)
    Line 2: contains a1, a2,  . . ., an (1 <= ai <= 1000)

Output

    Write the sum of elements of the subseq found

Example
Input
7
4 10 6 6 6 2 5 
Output
31
Explanation the subset found is: {4, 10, 6, 6, 5}
"""


def maxSubsetSum(n, arr):
    if n == 0:
        return 0
    if n == 1:
        return arr[0]
    if n == 2:
        return max(arr[0], arr[1])

    dp = [0] * n
    dp[0] = arr[0]
    dp[1] = max(arr[0], arr[1])
    dp[2] = max(arr[0] + arr[2], arr[1], arr[2])

    for i in range(3, n):
        dp[i] = max(dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i] + arr[i - 1])

    return max(dp[-1], dp[-2])


def main():
    n = int(input())
    arr = list(map(int, input().split()))
    result = maxSubsetSum(n, arr)
    print(result)


if __name__ == "__main__":
    main()
