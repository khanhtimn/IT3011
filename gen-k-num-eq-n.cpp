/*
Problem: Generate ways to represent n by sum of k non-decreasing positive integers
Description
Given two positive integers k and n. Write a program to generate (x1, x2, ..., xk) such that x1 <= x2 <= . . . <= xk and x1 + x2 + . . . + xk = n.
Input

    Line 1 contains: k and n (1 <= k <= n <= 40)

Output

    Each line contains: x1, x2, . . ., xk separated by a SPACE character

Example
Input
3  7
Output
1 1 5
1 2 4
1 3 3
2 2 3

*/
#include <iostream>
#include <vector>
using namespace std;

void findCombinations(vector<int>& combination, int start, int remainingSum, int remainingCount, int k, int n)
{
    if (combination.size() == k) {
        if (remainingSum == 0) {
            for (int num : combination) {
                cout << num << " ";
            }
            cout << endl;
        }
        return;
    }

    int maxVal = (remainingSum - (remainingCount - 1)) < n ? (remainingSum - (remainingCount - 1)) : n;

    for (int i = start; i <= maxVal; ++i) {
        if (remainingSum - i < 0)
            break;

        combination.push_back(i);
        findCombinations(combination, i, remainingSum - i, remainingCount - 1, k, n);
        combination.pop_back();
    }
}

void generateCombinations(int k, int n)
{
    vector<int> combination;
    findCombinations(combination, 1, n, k, k, n);
}

int main()
{
    int k, n;
    cin >> k >> n;

    generateCombinations(k, n);

    return 0;
}
