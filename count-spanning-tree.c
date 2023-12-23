/*
Count Spanning Tree
Description
Given a undirected connected graph G = (V,E) in which V = {1,…,N} is the set of nodes and E is the set of M edges. Count the number of spanning trees of G.
Input

    Line 1: contains positive integers N and M (1 <= N <= 20, 1 <= M <= 25)
    Line i+1 (i = 1,…, M): contains u and v which are endpoints of the ith

Output

    Write the number of spanning trees of G

Example
Input:
16 24
1 2
1 3
1 10
1 15
2 3
2 9
2 10
3 4
3 7
3 15
4 5
4 8
4 15
6 7
6 12
8 11
9 12
10 12
11 13
12 14
12 15
13 14
14 15
15 16

Output:
24416
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXN 21

int adj[MAXN][MAXN], deg[MAXN];
int N, M;

// Function to read the graph
void readGraph()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--; // Adjusting for 0-based indexing
        adj[u][v] = adj[v][u] = 1;
        deg[u]++;
        deg[v]++;
    }
}

// Function to perform Gaussian elimination
void gaussianElimination(double mat[MAXN][MAXN], int n)
{
    for (int i = 0; i < n; i++) {
        // Find pivot
        int pivot = i;
        for (int j = i + 1; j < n; j++)
            if (abs(mat[j][i]) > abs(mat[pivot][i]))
                pivot = j;

        // Swap rows
        if (pivot != i)
            for (int j = i; j < n; j++)
                mat[i][j] += mat[pivot][j] - (mat[pivot][j] = mat[i][j]);

        // Eliminate below
        for (int j = i + 1; j < n; j++) {
            double factor = mat[j][i] / mat[i][i];
            for (int k = i; k < n; k++)
                mat[j][k] -= mat[i][k] * factor;
        }
    }
}

// Function to calculate the determinant after Gaussian elimination
double determinantAfterGaussian(double mat[MAXN][MAXN], int n)
{
    double det = 1;
    for (int i = 0; i < n; i++)
        det *= mat[i][i];
    return det;
}

// Main function to calculate the number of spanning trees
int main()
{
    readGraph();

    double laplacian[MAXN][MAXN];

    // Constructing the Laplacian matrix
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j)
                laplacian[i][j] = (double)deg[i];
            else
                laplacian[i][j] = (double)-adj[i][j];
        }
    }

    // Apply Gaussian elimination
    gaussianElimination(laplacian, N - 1);

    // Calculate and print the number of spanning trees
    printf("%.0f\n", determinantAfterGaussian(laplacian, N - 1));

    return 0;
}
