/*
Problem: Tree manipulation count leaves and kChild nodes
Description
Thực hiện 1 chuỗi các hành động sau đây bao gồm các thao tác liên quan đến xây dựng cây và duyệt cây
· MakeRoot u: Tạo ra nút gốc u của cây
· Insert u v: tạo mới 1 nút u và chèn vào cuối danh sách nút con của nút v
· CountLeaves u:  đếm và trả ra số nút lá trên cây có gốc là u
· CountKChildren u k: đếm và trả về số nút có đúng k nút con trên cây gốc u
Biết rằng dữ liệu đầu vào có 1 lệnh duy nhất là MakeRoot và luôn ở dòng đầu tiên
· Dữ liệu: bao gồm các dòng, mỗi dòng có định dạng như mô tả ở trên, trong đó dòng cuối dùng ghi * (dấu hiệu kết thúc dữ liệu)
· Kết quả: ghi ra mỗi dòng kết quả của các lệnh CountLeaves và CountKChildren tương ứng đọc được từ đầu vào
Ví dụ:
Dữ liệu
MakeRoot 10
Insert 11 10
Insert 1 10
Insert 3 10
Insert 5 11
Insert 4 11
CountLeaves 4
CountKChildren 10 3
Insert 8 3
Insert 2 3
Insert 7 3
Insert 6 4
Insert 9 4
CountKChildren 10 3
CountLeaves 10
CountLeaves 3
*
Kết quả
1
1
2
7
3
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

Node* findNode(Node* root, int id)
{
    if (root == NULL)
        return NULL;
    if (root->id == id)
        return root;

    Node* result = findNode(root->children, id);
    if (result != NULL)
        return result;

    return findNode(root->next, id);
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

int CountLeaves(Node* root)
{
    if (root == NULL)
        return 0;
    if (root->children == NULL)
        return 1; // Nút lá

    int leafCount = 0;
    for (Node* child = root->children; child != NULL; child = child->next) {
        leafCount += CountLeaves(child);
    }

    return leafCount;
}

int countChildren(Node* root)
{
    int count = 0;
    for (Node* child = root->children; child != NULL; child = child->next) {
        count++;
    }
    return count;
}

int CountKChildren(Node* root, int k)
{
    if (root == NULL)
        return 0;

    int kChildCount = (countChildren(root) == k) ? 1 : 0;

    for (Node* child = root->children; child != NULL; child = child->next) {
        kChildCount += CountKChildren(child, k);
    }

    return kChildCount;
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
        } else if (strcmp(command, "CountLeaves") == 0) {
            int id;
            scanf("%d", &id);
            printf("%d\n", CountLeaves(findNode(root, id))); // findNode là hàm tìm nút có id cụ thể
        } else if (strcmp(command, "CountKChildren") == 0) {
            int id, k;
            scanf("%d %d", &id, &k);
            printf("%d\n", CountKChildren(findNode(root, id), k)); // findNode tương tự như trên
        }
    }

    // Giải phóng bộ nhớ và kết thúc chương trình
    // Code để giải phóng bộ nhớ của cây ở đây
    return 0;
}
