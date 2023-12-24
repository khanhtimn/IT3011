/*
Problem: All pair shortest paths
Description
Given a directed graph G = (V, E) in which V = {1, 2, ..., n} is the set of nodes, and w(u,v) is the weight (length) of the arc(u,v). Compute d(u,v) - the length of the shortest path from u to v in G, for all u,v in V.
Input
Line 1: contains 2 positive integers n and m (1 <= n,m <= 10000)
Line i+1 (i = 1, 2, ..., m): contains 3 positive integers u, v, w in which w is the weight of the arc (u,v) (1 <= w <= 1000)
Output
Line i (i = 1, 2, ..., n): wirte the ith row of the matrix d (if there is not any path from node i to node j, then d(i,j) = -1)
Example
Input
4 9
1 2 9
1 3 7
1 4 2
2 1 1
2 4 5
3 4 6
3 2 2
4 1 5
4 2 8
Output
0 9 7 2
1 0 8 3
3 2 0 5
5 8 12 0
*/
#include <stdio.h>
#include <stdlib.h>

#define INF 10000000

int main()
{
    int n, m, i, j, k, u, v, w;
    int** d;

    scanf("%d %d", &n, &m);

    d = (int**)malloc(n * sizeof(int*));
    for (i = 0; i < n; i++) {
        d[i] = (int*)malloc(n * sizeof(int));
        for (j = 0; j < n; j++) {
            if (i == j)
                d[i][j] = 0;
            else
                d[i][j] = INF;
        }
    }

    for (i = 0; i < m; i++) {
        scanf("%d %d %d", &u, &v, &w);
        d[u - 1][v - 1] = w;
    }

    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (d[i][k] + d[k][j] < d[i][j])
                    d[i][j] = d[i][k] + d[k][j];
            }
        }
    }

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (d[i][j] == INF)
                printf("-1 ");
            else
                printf("%d ", d[i][j]);
        }
        printf("\n");
    }

    // Free the allocated memory
    for (i = 0; i < n; i++) {
        free(d[i]);
    }
    free(d);

    return 0;
}
