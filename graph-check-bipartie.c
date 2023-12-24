/*
Problem: Check Bipartite Graph
Description
Given an undirected graph G=(V, E) in which V={1,…, N} is the set of nodes and |E|=M. You are required to write a program to check if G is a bipartite graph.

Input
Line 1 N and M (1≤N, M≤10
5
)
Line i+1 (i=1,…, M): u and v which are endpoints of the ith edge
Output
Write 1 if G is a bipartite graph and 0, otherwise.

Example
input
6 6
1 2
1 3
2 5
2 6
4 5
4 6

output
1
*/
#include <stdbool.h>
#include <stdio.h>

#define MAXN 100005

int color[MAXN];
int graph[MAXN][2]; // Store each edge as a pair of vertices
int n, m;

bool dfs(int v, int c)
{
    color[v] = c;
    for (int i = 0; i < m; ++i) {
        int u = (graph[i][0] == v) ? graph[i][1] : (graph[i][1] == v) ? graph[i][0]
                                                                      : -1;
        if (u != -1) {
            if (color[u] == -1) {
                if (!dfs(u, 1 - c))
                    return false;
            } else if (color[u] == c) {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    scanf("%d %d", &n, &m);

    // Initialize colors
    for (int i = 0; i < n; i++) {
        color[i] = -1;
    }

    // Read the edges
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &graph[i][0], &graph[i][1]);
        graph[i][0]--; // Adjusting for 0-based indexing
        graph[i][1]--;
    }

    // Check if the graph is bipartite
    bool bipartite = true;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!dfs(i, 0)) {
                bipartite = false;
                break;
            }
        }
    }

    printf("%d\n", bipartite ? 1 : 0);
    return 0;
}
