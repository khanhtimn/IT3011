/*
Problem: Sum of length of paths from root on a tree
Description
Given a tree T=(V,E) in which V={1,. . ., n} is the set of nodes. Each edge (u,v) of T has length w(u,v). Denote f(v) the sum of length of paths from all other nodes to v. Write a program to compute max{f(1), .  . ., f(n)}.

Input

    Line 1 contains a positive integer n (2 <= n <= 10^5)
    Line i+1 (i=1, . . ., n): contains u, v and w in which w is the weight of the edge (u,v)

Output

    Write the value max{f(1), . . , f(n}.


Example
Input
4
1 2 1
1 3 3
3 4 2
Output
13
*/
#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 100005;
vector<pair<int, int>> adj[MAXN]; // Store tree with weights
long long subtreeSize[MAXN]; // Number of nodes in each subtree
long long sumOfPaths = 0; // Total sum of all paths in the tree
long long f[MAXN]; // f(v) for each node
long long maxF = 0; // Maximum f(v)

void dfs1(int node, int parent)
{
    subtreeSize[node] = 1; // Count the node itself
    for (auto& [child, weight] : adj[node]) {
        if (child != parent) {
            dfs1(child, node);
            subtreeSize[node] += subtreeSize[child];
            sumOfPaths += subtreeSize[child] * weight;
        }
    }
}

void dfs2(int node, int parent, long long currentSum)
{
    f[node] = currentSum;
    maxF = max(maxF, f[node]);

    for (auto& [child, weight] : adj[node]) {
        if (child != parent) {
            long long childSum = currentSum - subtreeSize[child] * weight + (subtreeSize[1] - subtreeSize[child]) * weight;
            dfs2(child, node, childSum);
        }
    }
}

int main()
{
    int n, u, v, w;
    cin >> n;

    for (int i = 1; i < n; i++) {
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }

    dfs1(1, -1);
    dfs2(1, -1, sumOfPaths);

    cout << maxF << endl;
    return 0;
}
