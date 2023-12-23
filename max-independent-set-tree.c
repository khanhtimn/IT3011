/*
Problem: Max Independent Set on a Tree
Description
Cho cây T = (V,E) trong đó V = {1,…,n} là tập các đỉnh và E là tập gồm n-1 cạnh. Mỗi đỉnh v của đồ thị có trọng số w(v). Hãy chọn ra tập S các đỉnh sao cho hai đỉnh kề nhau không cùng được chọn và tổng trọng số các đỉnh được chọn là lớn nhất.
Dữ liệu
· Dòng 1: ghi 2 số nguyên dương n (1 <= n <= 20, 1 <= m <= 100)
· Dòng 2: ghi n số nguyên dương w(1), w(2), …, w(n) là trọng số các đỉnh tương ứng
· Dòng i+2 (i = 1,…,n-1): ghi 2 số nguyên dương u và v là 2 đầu mút của cạnh thứ i của T
Kết quả:
· Ghi ra tổng trọng số của các đỉnh được chọn
Ví dụ
Dữ liệu
9
9 5 10 4 3 2 6 1 8
1 5
2 3
2 4
2 6
3 5
6 7
6 8
6 9
Kết quả
38
*/
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_N 100001

int n;
int w[MAX_N];
int dp[MAX_N][2];
bool visited[MAX_N];
int head[MAX_N], to[2 * MAX_N], next[2 * MAX_N], cnt;

int max(int a, int b)
{
    return (a > b) ? a : b;
}

void addEdge(int u, int v)
{
    to[cnt] = v;
    next[cnt] = head[u];
    head[u] = cnt++;
}

void dfs(int v)
{
    visited[v] = true;
    dp[v][0] = 0;
    dp[v][1] = w[v];

    for (int i = head[v]; i != -1; i = next[i]) {
        int u = to[i];
        if (!visited[u]) {
            dfs(u);
            dp[v][0] += max(dp[u][0], dp[u][1]);
            dp[v][1] += dp[u][0];
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &w[i]);
    }

    memset(head, -1, sizeof(head));
    cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        addEdge(u, v);
        addEdge(v, u);
    }

    memset(visited, false, sizeof(visited));
    dfs(0);

    printf("%d\n", max(dp[0][0], dp[0][1]));
    return 0;
}
