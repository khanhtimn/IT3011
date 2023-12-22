/*
Problem: Xử lý cây phần 1
Description
Viết chương trình C thực hiện các công việc sau:
(1). Yêu cầu người dùng nhập vào N đại diện cho số nút có trên cây.
(2). Yêu cầu nhập vào N dòng, mỗi dòng có định dạng sau: chỉ số nút, số nút con của nút đó, danh sách các nút con cách nhau bởi dấu cách.
(3) chương trình in ra ra số lượng các nút mà tất cả các nút con trực tiếp của nó đều có số con là số chẵn khác 0. Ví dụ
Input:
10
1 3 2 3 4
2 2 5 6
3 2 7 8
4 2 9 10
5 0
6 0
7 0
8 0
9 0
10 0
Output:
1
chương trình sẽ in ra 1, vì chỉ có mỗi nút 1 là thoả mãn điều đó, nút đó có 3 con và tất cả các con đều có con cũng như số con là số chẵn.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int index;
    int numChildren;
    int* children;
};

int isAllChildrenEven(struct Node* nodes, int index)
{
    for (int i = 0; i < nodes[index].numChildren; i++) {
        if (nodes[nodes[index].children[i]].numChildren % 2 != 0 || nodes[nodes[index].children[i]].numChildren == 0) {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int N;
    scanf("%d", &N);

    struct Node* nodes = (struct Node*)malloc(N * sizeof(struct Node));

    // Khởi tạo nút và đọc dữ liệu đầu vào
    for (int i = 0; i < N; i++) {
        nodes[i].index = i + 1;
        scanf("%d", &nodes[i].numChildren);
        nodes[i].children = (int*)malloc(nodes[i].numChildren * sizeof(int));
        for (int j = 0; j < nodes[i].numChildren; j++) {
            scanf("%d", &nodes[i].children[j]);
        }
    }

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (isAllChildrenEven(nodes, i)) {
            count++;
        }
    }

    printf("%d\n", count);

    // Giải phóng bộ nhớ
    for (int i = 0; i < N; i++) {
        free(nodes[i].children);
    }
    free(nodes);

    return 0;
}
