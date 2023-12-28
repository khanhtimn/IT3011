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
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 100005;
vector<int> graph[MAXN];
int color[MAXN];
int n, m;

bool bfs(int s) {
    queue<int> q;
    q.push(s);
    color[s] = 0;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int u : graph[v]) {
            if (color[u] == -1) {
                color[u] = 1 - color[v];
                q.push(u);
            } else if (color[u] == color[v]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    cin >> n >> m;

    // Initialize colors
    fill(color, color + n, -1);

    // Read the edges and build the graph
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        --u; --v; // Adjust for 0-based indexing
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    // Check if the graph is bipartite
    bool bipartite = true;
    for (int i = 0; i < n; i++) {
        if (color[i] == -1) {
            if (!bfs(i)) {
                bipartite = false;
                break;
            }
        }
    }

    cout << (bipartite ? 1 : 0) << endl;
    return 0;
}
