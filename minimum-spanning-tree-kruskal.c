/*
Problem: Minimum Spanning Tree - Kruskal
Description
Given a undirected connected graph G=(V,E) where V={1,…,N}. Each edge (u,v)∈E(u,v)∈E has weight w(u,v)w(u,v). Compute minimum spanning tree of G.
Input

    Line 1: N and M (1≤N,M≤105) in which NN is the number of nodes and MM is the number of edges.
    Line i+1 (i=1,…,M): contains 3 positive integers u, v, and w where w is the weight of edge (u,v)

Output
Write the weight of the minimum spanning tree found.
Example
Input
5 8
1 2 1
1 3 4
1 5 1
2 4 2
2 5 1
3 4 3
3 5 3
4 5 2
Output
7
*/
#include <stdio.h>
#include <stdlib.h>

#define MAXN 100005

typedef struct {
    int u, v, weight;
} Edge;

Edge edges[MAXN];
int parent[MAXN];
int N, M;

// Function to compare edges based on their weight
int compareEdges(const void* a, const void* b)
{
    Edge* edgeA = (Edge*)a;
    Edge* edgeB = (Edge*)b;
    return edgeA->weight - edgeB->weight;
}

// Find set (with path compression)
int findSet(int i)
{
    if (parent[i] != i) {
        parent[i] = findSet(parent[i]);
    }
    return parent[i];
}

// Union of two sets
void unionSet(int a, int b)
{
    int rootA = findSet(a);
    int rootB = findSet(b);
    if (rootA != rootB) {
        parent[rootB] = rootA;
    }
}

// Function to compute MST using Kruskal's algorithm
int kruskal()
{
    int mstWeight = 0;

    qsort(edges, M, sizeof(Edge), compareEdges);

    for (int i = 0; i < N; i++) {
        parent[i] = i;
    }

    for (int i = 0; i < M; i++) {
        int u = edges[i].u;
        int v = edges[i].v;
        int w = edges[i].weight;

        if (findSet(u) != findSet(v)) {
            mstWeight += w;
            unionSet(u, v);
        }
    }

    return mstWeight;
}

int main()
{
    scanf("%d %d", &N, &M);
    for (int i = 0; i < M; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
        edges[i].u--; // Adjust for 0-based indexing
        edges[i].v--; // Adjust for 0-based indexing
    }

    printf("%d\n", kruskal());

    return 0;
}
