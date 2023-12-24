/*
Problem: Find Weight of a Path on a Graph
Description
Cho đồ thị có hướng G = (V,E) và dãy các đỉnh x1, x2, …, xk. Hãy viết chương trình tính đồ dài của đường đi x1, x2, . . ., xk (nếu dãy đỉnh đó lập thành một đường đi).
Input
Dòng 1: ghi 2 số nguyên dương n và m là số đỉnh và số cung của G
Dòng i+1 (i = 1,.., m): ghi 3 số nguyên dương u, v, w trong đó w là trọng số cung (u,v)
Dòng m+2: ghi số nguyên dương k
Dòng m+3: ghi x1, x2, …, xk
Output
Nếu dãy x1, x2, …, xk là một đường đi thì ghi ra độ dài của nó và ghi ra -1 nếu ngược lại
Example
Input
6 8
6 1 2
3 1 7
2 4 9
5 2 6
2 6 4
4 3 7
3 6 5
5 4 2
4
5 2 6 1
Output
12
*/
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);

    // Tạo và khởi tạo ma trận trọng số.
    int** graph = (int**)malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        graph[i] = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            graph[i][j] = -1; // -1 biểu thị không có cạnh trực tiếp giữa i và j.
        }
    }

    // Đọc dữ liệu cung và trọng số.
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        graph[u - 1][v - 1] = w; // Giả sử đỉnh đánh số từ 1.
    }

    // Đọc dãy đỉnh.
    int k;
    scanf("%d", &k);
    int path[k];
    for (int i = 0; i < k; i++) {
        scanf("%d", &path[i]);
        path[i]--; // Đưa về đánh số từ 0.
    }

    // Tính toán độ dài đường đi.
    int path_length = 0;
    for (int i = 0; i < k - 1; i++) {
        if (graph[path[i]][path[i + 1]] == -1) {
            path_length = -1;
            break;
        }
        path_length += graph[path[i]][path[i + 1]];
    }

    // In kết quả.
    printf("%d\n", path_length);

    // Giải phóng bộ nhớ.
    for (int i = 0; i < n; i++) {
        free(graph[i]);
    }
    free(graph);

    return 0;
}
