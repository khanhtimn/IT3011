/*
Problem: Count number of Queen solutions with some specified queens
Description
Given a chess board N x N on which there are K being placed in some cells. Compute the number of solutions to place other N - K queens in other cells such that among N queens on the board, no two queens attack each other.
A board is represented by a NxN matrix A in which A[i,j] = 1 if there is a queen placed in cell (i,j), and A[i,j] = 0, otherwise.

Input

    Line 1: contains a positive integer N (1 <= N <= 12)
    Line i+1 (i = 1, 2, . . ., N): contains the ith row of the matrix A

Output

    Write the number of solutions


Example
Input
4
0 1 0 0
0 0 0 0
0 0 0 0
0 0 1 0
Output
1


Input
5
0 1 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
0 0 0 0 0
Output
2
*/
