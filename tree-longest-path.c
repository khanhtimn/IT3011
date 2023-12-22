/*
Problem: Longest Path on a Tree
Description
Given a undirected tree $G = (V, E)$ in which $V = \{1,…,N\}$ is the set of nodes. Each edge $(u,v) \in E$ has weight $w(u,v)$. The length of a path is defined to be the sum of weights of edges of this path. Find the longest elementary path on $G$.
Input

    Line 1: positive integer $N$ ($1 \leq N \leq 10^5$)
    Line $i + 1$ ($i = 1,…,N-1$): positive integers $u, v, w$ in which $w$ is the weight of edge $(u,v)$ (1 ≤ w ≤ 100)

Output
The weight of the longest path on the given tree
Example
Input
6
1 3 3
 1 6 2
2 6 5
4 5 2
 4 6 1
Output
10
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
    int node;
    int weight;
    struct Edge* next;
} Edge;

Edge* create_edge(int node, int weight)
{
    Edge* new_edge = (Edge*)malloc(sizeof(Edge));
    new_edge->node = node;
    new_edge->weight = weight;
    new_edge->next = NULL;
    return new_edge;
}

void add_edge(Edge** adjacency_list, int u, int v, int weight)
{
    Edge* new_edge = create_edge(v, weight);
    new_edge->next = adjacency_list[u];
    adjacency_list[u] = new_edge;
}

void dfs(Edge** adjacency_list, int current, int parent, int current_length, int* max_length, int* farthest_node)
{
    if (current_length > *max_length) {
        *max_length = current_length;
        *farthest_node = current;
    }

    for (Edge* edge = adjacency_list[current]; edge != NULL; edge = edge->next) {
        if (edge->node != parent) {
            dfs(adjacency_list, edge->node, current, current_length + edge->weight, max_length, farthest_node);
        }
    }
}

int main()
{
    int n, u, v, w;
    scanf("%d", &n);

    Edge* adjacency_list[n + 1];
    for (int i = 1; i <= n; i++) {
        adjacency_list[i] = NULL;
    }

    for (int i = 1; i < n; i++) {
        scanf("%d %d %d", &u, &v, &w);
        add_edge(adjacency_list, u, v, w);
        add_edge(adjacency_list, v, u, w);
    }

    int max_length = 0, farthest_node = 1;
    dfs(adjacency_list, 1, 0, 0, &max_length, &farthest_node);

    max_length = 0;
    dfs(adjacency_list, farthest_node, 0, 0, &max_length, &farthest_node);

    printf("%d\n", max_length);

    // Free memory and perform cleanup here if necessary

    return 0;
}
