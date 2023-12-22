/*
Problem: Write a function to count nodes having 2 children of a binary tree
Description
Cấu trúc dữ liệu mỗi nút của một cây nhị phân bao gồm các thông tin sau:
typedef struct Node{
    int id;
    struct Node* leftChild; // con trỏ trỏ đến nút con trái
    struct Node* rightChild; // con trỏ trỏ đến nút con phải
}Node;

Hãy lập trình hàm int countNodesWith2Children(Node* r) để đếm và trả về số nút trên cây gốc r có đúng 2 nút con. Hàm này được thiết kế trong khung code được cho sẵn, sinh viên chỉ cần viết nội dung của hàm.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node {
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* makeNode(int u)
{
    Node* p = (Node*)malloc(sizeof(Node));
    p->leftChild = NULL;
    p->rightChild = NULL;
    p->id = u;
    return p;
}
Node* find(int u, Node* r)
{
    if (r == NULL)
        return NULL;
    if (r->id == u)
        return r;
    Node* p = find(u, r->leftChild);
    if (p != NULL)
        return p;
    return find(u, r->rightChild);
}
void addLeft(int u, int v, Node* r)
{
    // printf("addLeft, u = %d, v= %d\n",u,v);
    Node* p = find(v, r);
    // printf("addLeft, u = %d, v= %d, finished find\n",u,v);
    if (p == NULL)
        return;

    // printf("addLeft, u = %d, v= %d, p not null\n",u,v);
    if (p->leftChild != NULL)
        return;
    Node* q = find(u, r);
    if (q != NULL)
        return; // node having id = u exists -> do not insert more
    p->leftChild = makeNode(u);
}
void addRight(int u, int v, Node* r)
{
    Node* p = find(v, r);
    if (p == NULL)
        return;
    // printf("addRight, u = %d, v= %d, p not null\n",u,v);
    if (p->rightChild != NULL)
        return;
    Node* q = find(u, r);
    if (q != NULL)
        return; // node having id = u exists -> do not insert more
    p->rightChild = makeNode(u);
}
void inOrder(Node* r)
{
    if (r == NULL)
        return;
    inOrder(r->leftChild);
    printf("%d ", r->id);
    inOrder(r->rightChild);
}
void preOrder(Node* r)
{
    if (r == NULL)
        return;
    printf("%d ", r->id);
    preOrder(r->leftChild);
    preOrder(r->rightChild);
}
void postOrder(Node* r)
{
    if (r == NULL)
        return;
    postOrder(r->leftChild);
    postOrder(r->rightChild);
    printf("%d ", r->id);
}
int countNodesWith2Children(Node* r)
{
    if (r == NULL)
        return 0;

    int leftChildren = countNodesWith2Children(r->leftChild);
    int rightChildren = countNodesWith2Children(r->rightChild);

    if (r->leftChild != NULL && r->rightChild != NULL) {
        return leftChildren + rightChildren + 1;
    } else {
        return leftChildren + rightChildren;
    }
}

int main()
{
    // freopen("test/2.txt","r",stdin);

    char cmd[100];
    Node* root = NULL;
    while (1) {
        scanf("%s", cmd);
        // printf("cmd = %s\n",cmd);
        if (strcmp(cmd, "#") == 0)
            break;
        else if (strcmp(cmd, "MakeRoot") == 0) {
            int u;
            scanf("%d", &u);
            root = makeNode(u);
            // inOrder(root);
        } else if (strcmp(cmd, "AddLeft") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            // printf("process addLeft, u = %d, v= %d\n",u,v);
            addLeft(u, v, root);
            // inOrder(root);
        } else if (strcmp(cmd, "AddRight") == 0) {
            int u, v;
            scanf("%d%d", &u, &v);
            addRight(u, v, root);
            // inOrder(root);
        } else {
            // do nothing
        }
    }
    int ans = countNodesWith2Children(root);
    printf("%d", ans);
    return 0;
}
