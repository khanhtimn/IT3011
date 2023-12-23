/*
Problem: Tree manipulation & Traversal
Description
Mỗi nút trên cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không chèn thêm mới)
· PreOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự trước
· InOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự giữa
· PostOrder: in ra thứ tự các nút trong phép duyệt cây theo thứ tự sau
Dữ liệu: bao gồm các dòng, mỗi dòng là 1 trong số các hành động được mô tả ở trên, dòng cuối dùng là * (đánh dấu sự kết thúc của dữ liệu).
Kết quả: ghi ra trên mỗi dòng, thứ tự các nút được thăm trong phép duyệt theo thứ tự trước, giữa, sau của các hành động PreOrder, InOrder, PostOrder tương ứng đọc được từ dữ liệu đầu vào
Ví dụ
Dữ liệu
MakeRoot 10
Insert 11 10
Insert 1 10
Insert 3 10
InOrder
Insert 5 11
Insert 4 11
Insert 8 3
PreOrder
Insert 2 3
Insert 7 3
Insert 6 4
Insert 9 4
InOrder
PostOrder
*
Kết quả
11 10 1 3
10 11 5 4 1 3 8
5 11 6 4 9 10 1 8 3 2 7
5 6 9 4 11 1 8 2 7 3 10
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* children;
    struct Node* next;
} Node;

Node* createNode(int id)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->children = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** root, int id, int parentId)
{
    if (*root == NULL)
        return;

    if ((*root)->id == parentId) {
        // Nếu nút cha đã có nút con, chèn vào cuối danh sách nút con
        Node* child = (*root)->children;
        if (child == NULL) {
            (*root)->children = createNode(id);
        } else {
            while (child->next != NULL) {
                child = child->next;
            }
            child->next = createNode(id);
        }
    } else {
        // Duyệt đệ quy qua các nút con
        insertNode(&((*root)->children), id, parentId);
        insertNode(&((*root)->next), id, parentId);
    }
}

void preOrder(Node* root)
{
    if (root == NULL)
        return;
    printf("%d ", root->id);
    preOrder(root->children);
    preOrder(root->next);
}

void inOrder(Node* root)
{
    if (root == NULL)
        return;

    // Duyệt qua nút con đầu tiên
    if (root->children != NULL) {
        Node* child = root->children;
        inOrder(child);

        // In ra nút hiện tại sau khi duyệt qua nút con đầu tiên
        printf("%d ", root->id);

        // Duyệt qua các nút con còn lại
        child = child->next;
        while (child != NULL) {
            inOrder(child);
            child = child->next;
        }
    } else {
        // Nếu không có nút con, chỉ in ra nút hiện tại
        printf("%d ", root->id);
    }
}

void postOrder(Node* root)
{
    if (root == NULL)
        return;
    postOrder(root->children);
    printf("%d ", root->id);
    postOrder(root->next);
}

int main()
{
    Node* root = NULL;
    char command[50];

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "*") == 0)
            break;

        if (strcmp(command, "MakeRoot") == 0) {
            int id;
            scanf("%d", &id);
            root = createNode(id);
        } else if (strcmp(command, "Insert") == 0) {
            int id, parentId;
            scanf("%d %d", &id, &parentId);
            insertNode(&root, id, parentId);
        } else if (strcmp(command, "PreOrder") == 0) {
            preOrder(root);
            printf("\n");
        } else if (strcmp(command, "InOrder") == 0) {
            inOrder(root);
            printf("\n");
        } else if (strcmp(command, "PostOrder") == 0) {
            postOrder(root);
            printf("\n");
        }
    }

    // Free the tree
    return 0;
}
