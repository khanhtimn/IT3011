/*
Problem: Graph Isomophism
Description
Cho 2 đồ thị vô hướng G1 = (V1, E1) và G2 = (V2, E2) trong đó V1 = {1,…,n1} là tập đỉnh của G1 và G2 = {1,2,…,n2} là tập đỉnh của G2. Hai đồ thị được gọi là đẳng cấu nếu tồn tại một song ánh f từ V1 đến V2 sao cho (u,v) là cạnh của G1 khi vào chỉ khi (f(u), f(v)) là một cạnh của G2.
Dữ liệu
· Dòng 1: ghi số nguyên dương n1 và m1  (1 <= n1 <= 20, 1 <= m1 <= 40) tương ứng là số đỉnh và số cạnh của G1
· Dòng thứ i+1 (i=1,…,n1): ghi 2 số nguyên dương u và v là đầu mút của cạnh thứ i của G1
· Dòng thứ m1 + 2: ghi 2 số nguyên dương n2 và m2 (1 <= n2 <= 20, 1 <= m2 <= 40) tương ứng là số đỉnh và số cạnh của G2
· Dòng thứ m1 + 2 + i (i = 1,…,m2): ghi 2 số nguyên dương u và v là đầu mút của cạnh thứ i của G2
Kết quả
· Ghi ra giá trị 1 nếu G1 và G2 đẳng cấu và ghi ra giá trị 0, nếu ngược lại
Ví dụ
Dữ liệu
4 5
1 2
1 3
2 3
2 4
3 4
4 5
1 2
1 3
1 4
2 3
3 4
Kết quả
1
*/
#include <stdio.h>

int n1, m1, n2, m2;
int g1[21][21], g2[21][21];
int visited[21], mapping[21];

// Hàm kiểm tra xem hai đồ thị có đẳng cấu không
int areIsomorphic()
{
    for (int i = 1; i <= n1; i++) {
        for (int j = 1; j <= n1; j++) {
            if (g1[i][j] != g2[mapping[i]][mapping[j]])
                return 0;
        }
    }
    return 1;
}

// Hàm sinh các hoán vị đề kiểm tra đẳng cấu
int generatePermutation(int index)
{
    if (index > n1)
        return areIsomorphic();

    for (int i = 1; i <= n2; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            mapping[index] = i;
            if (generatePermutation(index + 1))
                return 1;
            visited[i] = 0;
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d", &n1, &m1);
    for (int i = 0; i < m1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g1[u][v] = g1[v][u] = 1;
    }

    scanf("%d %d", &n2, &m2);
    for (int i = 0; i < m2; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        g2[u][v] = g2[v][u] = 1;
    }

    if (n1 != n2 || m1 != m2) {
        printf("0\n");
        return 0;
    }

    printf("%d\n", generatePermutation(1));
    return 0;
}
