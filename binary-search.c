/*
Problem: Binary Search - midterm 13112
Description
You are given mxn integers that are stored in a 2D matrix of size mxn and satisfied the following properties:

    Values in each row are sorted in ascending order from left to right.
    The first value of each row is greater than the last integer of the previous row.

and an integer value target.
Determine whether target appears in the matrix or not.
Note: You must use binary search, otherwise you get 0
Input:
· The first line contains 2 integers: m and n (m is number of rows, n is number of columns, 1<= m,n <=1000)
· Then m lines follow. The i-th of them contains n integers (each integer is in the range of [-108 , 108])
· The last line contains one integer target (-108 <= target <=  108)
Ouput:
Print two integers : the index of row and index of column in which the target appears in the matrix (there is one space between two indexes),
if target does not appear in the matrix, print -1  -1 (Note that: the index of row (column) of the matrix is numbered from 1).
Example:
Input:
3 4
1 3 5 7
10 11 16 20
23 30 34 60
3
Output:
1 2
Explanation: in the above example, m = 3, n = 4, the target = 3 and it appears in the matrix at row 1, column 2
*/
#include <stdio.h>

int main()
{
    int m, n, target;
    scanf("%d %d", &m, &n);
    int matrix[m][n];

    // Reading matrix
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Reading target
    scanf("%d", &target);

    // Binary Search
    int low = 0, high = m * n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int midValue = matrix[mid / n][mid % n];

        if (midValue == target) {
            printf("%d %d\n", mid / n + 1, mid % n + 1); // Converting to 1-based index
            return 0;
        } else if (midValue < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    // Target not found
    printf("-1 -1\n");
    return 0;
}
