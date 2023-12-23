/*
Problem: Tree manipulation query depth - height
Description
Mỗi nút trên 1 cây có trường id (identifier) là một số nguyên (id của các nút trên cây đôi một khác nhau)
Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v (nếu nút có id bằng v không tồn tại hoặc nút có id bằng u đã tồn tại thì không thêm mới)
· Height u:  Tính và trả về độ cao của nút u
· Depth u: Tính và trả về độ sâu của nút u
Biết rằng dữ liệu đầu vào có 1 lệnh duy nhất là MakeRoot và luôn ở dòng đầu tiên
· Dữ liệu: bao gồm các dòng, mỗi dòng có định dạng như mô tả ở trên, trong đó dòng cuối dùng ghi * (dấu hiệu kết thúc dữ liệu)
· Kết quả: ghi ra mỗi dòng kết quả của các lệnh Height và Depth tương ứng đọc được từ đầu vào
Ví dụ:
Dữ liệu
MakeRoot 10
Insert 11 10
Insert 1 10
Insert 3 10
Insert 5 11
Insert 4 11
Height 10
Depth 10
Insert 8 3
Insert 2 3
Insert 7 3
Insert 6 4
Insert 9 4
Height 10
Depth 10
Depth 3
*
Kết quả
3
1
4
1
2
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

int maxHeight(Node* root)
{
    if (root == NULL)
        return -1; // Trường hợp cơ sở

    int maxH = -1;
    for (Node* child = root->children; child != NULL; child = child->next) {
        int childHeight = maxHeight(child);
        if (childHeight > maxH) {
            maxH = childHeight;
        }
    }

    return maxH + 1; // Tăng độ cao khi quay trở về nút cha
}

int Height(Node* root, int id)
{
    if (root == NULL)
        return -1;
    if (root->id == id)
        return maxHeight(root);

    int childHeight = Height(root->children, id);
    if (childHeight >= 0)
        return childHeight;

    return Height(root->next, id);
}

int Depth(Node* root, int id, int depth)
{
    if (root == NULL)
        return -1;
    if (root->id == id)
        return depth;

    // Kiểm tra trong cây con
    int childDepth = Depth(root->children, id, depth + 1);
    if (childDepth != -1)
        return childDepth;

    // Kiểm tra trong nút anh em
    return Depth(root->next, id, depth);
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
        } else if (strcmp(command, "Height") == 0) {
            int id;
            scanf("%d", &id);
            printf("%d\n", 1 + Height(root, id));
        } else if (strcmp(command, "Depth") == 0) {
            int id;
            scanf("%d", &id);
            printf("%d\n", 1 + Depth(root, id, 0));
        }
    }

    // Giải phóng bộ nhớ và kết thúc chương trình
    // Code để giải phóng bộ nhớ của cây ở đây
    return 0;
}
