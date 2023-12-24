/*
Problem: TRANVANDANG_check_max_heap
Description
Cho cấu trúc dữ liệu cây nhị phân:
typedef struct Node{
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;
Mỗi nút của một cây nhị phân T có trường id (định danh của nút, id không trùng lặp nhau).
Một cây nhị phân được gọi là max-heap nếu như id của mỗi nút đều lớn hơn id của các nút con của nó.
Thực hiện chuỗi các thao tác sau đây trên cây T (ban đầu, T là cây rỗng)

    MakeRoot u: tạo một nút gốc có id bằng u
    AddLeftChild <cur_id> <child_id>: thêm nútcon trái<child_id> (nếu chưa tồn tại) vào nút định danh<cur_id> trên cây nếu <cur_id> tồn tại
    AddRightChild <cur_id> <child_id>: thêmcon phải<child_id> (nếu chưa tồn tại) vào nút có định danh<cur_id> vào cây nếu <cur_id> tồn tại
    IsMaxHeap <cur_id>: In ra màn hình 1 nếu cây con mà có gốc là nút định danh<cur_id> là 1 max-heap, in ra 0 trong trường hợp còn lại. Nếu như không có nút định danh <cur_id> thì in ra 1.

Input

    Mỗi dòng là 1 trong số cách thao tác với định dạng được mô tả ở trên (thao tác MakeRoot chỉ xuất hiện đúng 1 lần và luôn ở ngay dòng đầu tiên). Kết thúc của dữ liệu input là dòng chứa duy nhất từ Quit

Output

    Ghi ra trên 1 dòng kết quả của thao tác mô tả ở trên

Example
Input
MakeRoot 1
AddLeftChild 1 2
AddRightChild 2 3
AddRightChild 3 4
AddRightChild 1 5
IsMaxHeap 2
Quit
Output
0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int id;
    struct Node* leftChild;
    struct Node* rightChild;
} Node;

Node* createNode(int id)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->id = id;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

Node* insertNode(Node* root, int cur_id, int child_id, char child_type)
{
    if (root == NULL)
        return NULL;
    if (root->id == cur_id) {
        Node* childNode = createNode(child_id);
        if (child_type == 'L')
            root->leftChild = childNode;
        else
            root->rightChild = childNode;
        return root;
    }
    insertNode(root->leftChild, cur_id, child_id, child_type);
    insertNode(root->rightChild, cur_id, child_id, child_type);
    return root;
}

Node* findNode(Node* root, int id)
{
    if (root == NULL)
        return NULL;
    if (root->id == id)
        return root;
    Node* foundNode = findNode(root->leftChild, id);
    if (foundNode != NULL)
        return foundNode;
    return findNode(root->rightChild, id);
}

int isMaxHeap(Node* root)
{
    if (root == NULL)
        return 1;
    if (root->leftChild && root->id < root->leftChild->id)
        return 0;
    if (root->rightChild && root->id < root->rightChild->id)
        return 0;
    return isMaxHeap(root->leftChild) && isMaxHeap(root->rightChild);
}

int main()
{
    char command[20];
    int u, cur_id, child_id;
    Node* root = NULL;

    while (1) {
        scanf("%s", command);
        if (strcmp(command, "Quit") == 0)
            break;

        if (strcmp(command, "MakeRoot") == 0) {
            scanf("%d", &u);
            root = createNode(u);
        } else if (strcmp(command, "AddLeftChild") == 0) {
            scanf("%d %d", &cur_id, &child_id);
            root = insertNode(root, cur_id, child_id, 'L');
        } else if (strcmp(command, "AddRightChild") == 0) {
            scanf("%d %d", &cur_id, &child_id);
            root = insertNode(root, cur_id, child_id, 'R');
        } else if (strcmp(command, "IsMaxHeap") == 0) {
            scanf("%d", &cur_id);
            Node* curNode = findNode(root, cur_id);
            printf("%d\n", isMaxHeap(curNode));
        }
    }
    return 0;
}
