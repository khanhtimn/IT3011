/*
Problem: Max Matching on Bipartie Graph
Description
There are  n tasks 1,. . .,n and m staffs 1, . . , m. T(i) is the set of staffs that can perform the task i (i=1, . . ., n). Compute an assignment of staffs to tasks such that each task is assigned to at most one staff and each staff cannot be assigned to more than one task and the number of tasks assigned is maximal.
Input
Line 1: contains 2 positive integer n và m (1 <=  n,m <= 10000)
Line i+1 (i=1, . . .,n) contains a positive integer k and k integer of T(i)
Output
Write the maximum number of tasks that are assigned to staffs.
Example
Input
3 4
2 1 4
2 1 3
1 2

Output
3
*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAXN 10001
#define NIL 0
#define INF (1 << 28)

int n, m, pairU[MAXN], pairV[MAXN], dist[MAXN];
int adj[MAXN][MAXN], adjSize[MAXN];

bool bfs()
{
    int queue[MAXN], qFront = 0, qBack = 0;
    for (int u = 1; u <= n; u++) {
        if (pairU[u] == NIL) {
            dist[u] = 0;
            queue[qBack++] = u;
        } else {
            dist[u] = INF;
        }
    }
    dist[NIL] = INF;

    while (qFront < qBack) {
        int u = queue[qFront++];
        if (dist[u] < dist[NIL]) {
            for (int i = 0; i < adjSize[u]; i++) {
                int v = adj[u][i];
                if (dist[pairV[v]] == INF) {
                    dist[pairV[v]] = dist[u] + 1;
                    queue[qBack++] = pairV[v];
                }
            }
        }
    }
    return (dist[NIL] != INF);
}

bool dfs(int u)
{
    if (u != NIL) {
        for (int i = 0; i < adjSize[u]; i++) {
            int v = adj[u][i];
            if (dist[pairV[v]] == dist[u] + 1) {
                if (dfs(pairV[v])) {
                    pairV[v] = u;
                    pairU[u] = v;
                    return true;
                }
            }
        }
        dist[u] = INF;
        return false;
    }
    return true;
}

int hopcroftKarp()
{
    memset(pairU, 0, sizeof(pairU));
    memset(pairV, 0, sizeof(pairV));
    memset(dist, 0, sizeof(dist));
    int matching = 0;
    while (bfs()) {
        for (int u = 1; u <= n; u++) {
            if (pairU[u] == NIL && dfs(u))
                matching++;
        }
    }
    return matching;
}

int main()
{
    scanf("%d %d", &n, &m);
    memset(adjSize, 0, sizeof(adjSize));

    for (int i = 1; i <= n; i++) {
        int k, staff;
        scanf("%d", &k);
        while (k--) {
            scanf("%d", &staff);
            adj[i][adjSize[i]++] = staff;
        }
    }

    printf("%d\n", hopcroftKarp());
    return 0;
}
