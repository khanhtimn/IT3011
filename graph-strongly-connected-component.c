/*
Problem: Compute Strongly Connected Components of directed graphs
Description
Given a directed graph G=(V,E) where V={1,. . ., N} is the number of nodes and the set E has M arcs. Compute number of strongly connected components of G
Input
Line 1: two positive integers N and M (1 <= N <= 10
5
, 1 <= M <= 10
6
)
Line i+1 (i=1,. . ., M\): contains two positive integers u and v which are endpoints of i
th
 arc
Output
Write the number of strongly connected components of G
Example
Input
8 13
1 2
1 8
2 3
2 6
3 6
4 3
4 6
5 4
6 5
7 1
7 2
7 6
8 7
Output
3
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_N 100005

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

int N, M;
int visited[MAX_N], stack[MAX_N], stackTop = -1;
Node *adj[MAX_N], *adjRev[MAX_N];
int componentCount = 0;

Node* createNode(int v)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

void addEdge(Node* adj[], int start, int end)
{
    Node* newNode = createNode(end);
    newNode->next = adj[start];
    adj[start] = newNode;
}

void dfs1(int v)
{
    visited[v] = 1;
    Node* temp = adj[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs1(temp->vertex);
        }
        temp = temp->next;
    }
    stack[++stackTop] = v;
}

void dfs2(int v)
{
    visited[v] = 1;
    Node* temp = adjRev[v];
    while (temp != NULL) {
        if (!visited[temp->vertex]) {
            dfs2(temp->vertex);
        }
        temp = temp->next;
    }
}

void findSCCs()
{
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            dfs1(i);
        }
    }

    for (int i = 1; i <= N; i++) {
        visited[i] = 0;
    }

    while (stackTop != -1) {
        int v = stack[stackTop--];
        if (!visited[v]) {
            dfs2(v);
            componentCount++;
        }
    }
}

int main()
{
    scanf("%d %d", &N, &M);

    for (int i = 1; i <= N; i++) {
        adj[i] = NULL;
        adjRev[i] = NULL;
    }

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(adj, u, v);
        addEdge(adjRev, v, u);
    }

    findSCCs();

    printf("%d\n", componentCount);

    return 0;
}
