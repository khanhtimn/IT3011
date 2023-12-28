/*
Problem: Check if a undirected graph can be oriented
Description
Given undirected graph G = (V,E) in which V = {1,2,...,n} is the set of nodes. G is called orientable if we can assign a direction to each edge of G such that the obtained directed graph is strongly connected. Write a program to check whether or not G is orientable.
Input
Line 1: contains a positive integer T which is the number of graph (1 <= T <= 100)
Subsequence lines are blocks of T graphs. Each block is under the following format:
Line 1: contains two positive integers n and m which are the number of nodes and the number of edges of the graph
Line i + 1 (i = 1,...,m): contains u and v which are two end-points of the i
th
 edge

Output
Contains T lines corresponding to the answers of T graphs, each line contains 1 if the corresponding graph if orientable and contains 0, otherwise

Example
Input
3
4 4
1 2
1 3
2 4
3 4
10 12
1 10
10 2
10 3
2 4
4 5
5 2
3 6
6 7
7 3
7 8
8 9
9 7
4 3
1 2
2 3
3 4

Output
1
0
0
*/
#include <iostream>
#include <vector>
using namespace std;

void dfs(int node, vector<int>& visited, vector<vector<int>>& adj)
{
    visited[node] = 1;
    for (auto& next : adj[node]) {
        if (!visited[next]) {
            dfs(next, visited, adj);
        }
    }
}

bool isConnected(int n, vector<vector<int>>& adj)
{
    vector<int> visited(n + 1, 0);
    int start_node;
    for (start_node = 1; start_node <= n; ++start_node) {
        if (adj[start_node].size() > 0)
            break;
    }
    dfs(start_node, visited, adj);
    for (int i = 1; i <= n; ++i) {
        if (adj[i].size() > 0 && !visited[i])
            return false;
    }
    return true;
}

bool isOrientable(int n, vector<pair<int, int>>& edges)
{
    vector<vector<int>> adj(n + 1);
    vector<int> degree(n + 1, 0);
    for (auto& edge : edges) {
        adj[edge.first].push_back(edge.second);
        adj[edge.second].push_back(edge.first);
        degree[edge.first]++;
        degree[edge.second]++;
    }
    if (!isConnected(n, adj))
        return false;
    for (int i = 1; i <= n; ++i) {
        if (degree[i] % 2 != 0)
            return false;
    }
    return true;
}

int main()
{
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> edges(m);
        for (int i = 0; i < m; ++i) {
            cin >> edges[i].first >> edges[i].second;
        }
        cout << (isOrientable(n, edges) ? 1 : 0) << endl;
    }
    return 0;
}
