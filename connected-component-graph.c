/*
Problem: Connected Components of undirected graphs
Description
Given a undirected graph G=(V,E) where V={1,. . .,N} is the number of nodes and the set E has M edges. Compute the number of connected components of G.
Input

    Line 1: two positive integers N and M (1 <= N <= 105, 1 <= M <= 105)
    Line i+1 (i=1, . . .,M): contains two positive integers u and v which are endpoints of ith edge

Output
Write the number of connected components of G.

Example
Input
8 8
1 2
1 7
1 8
2 7
4 5
4 6
5 6
7 8

Output
3
*/
#include <stdio.h>

#define MAX_N 100000

int parent[MAX_N + 1];

int find(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = find(parent[x]);
}

void unionSets(int x, int y)
{
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY)
        parent[rootX] = rootY;
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 1; i <= M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        unionSets(u, v);
    }

    int connectedComponents = 0;
    for (int i = 1; i <= N; i++) {
        if (parent[i] == i)
            connectedComponents++;
    }

    printf("%d\n", connectedComponents);

    return 0;
}
