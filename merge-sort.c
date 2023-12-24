/*
Problem: DOANPHONGTUNG_Sap_Xep_Tron
Description
Cho cấu trúc sau:
typedef struct Node {
char name[MAX_LEN];
float grade;
struct Node* previous;
struct Node* next;
} Node;
dùng để lưu thông tin sinh viên gồm tên (name) và điểm (grade). Hãy xây dựng danh sách sinh viên và sắp xếp danh sách đó theo thứ tự tăng dần bằng một trong ba giải thuật Merge Sort.
Mô tả dữ liệu vào-ra:

    Dữ liệu vào gồm nhiều dòng, mỗi dòng gồm tên và điểm của một sinh viên ngăn cách nhau bởi dấu cách. Kết thúc việc nhập tên và điểm của sinh viên bằng một dòng chứa dấu #.
    Dữ liệu ra danh sách tên của sinh viên (ngăn cách với nhau bởi dấu cách) sau khi đã sắp xếp

Ví dụ:
Input:
Thuy 5.5
Dang 6.5
Anh 4.5
Tung 10
Khoat 8.0
Truc 9.5
Linh 7.0
#
Output:
Anh Thuy Dang Linh Khoat Truc Tung
Lưu ý:
Điểm của sinh viên phải trong khoảng từ 0 đến 10, nếu nằm ngoài khoảng này thì không lưu vào dánh sách liên kết.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Định nghĩa cấu trúc Node
#define MAX_LEN 100
typedef struct Node {
    char name[MAX_LEN];
    float grade;
    struct Node* previous;
    struct Node* next;
} Node;

// Khai báo hàm
Node* createNode(char* name, float grade);
void append(Node** head, char* name, float grade);
Node* mergeSort(Node* head);
Node* merge(Node* first, Node* second);
void printList(Node* node);
void freeList(Node* node);

// Hàm chính
int main()
{
    Node* head = NULL;
    char name[MAX_LEN];
    float grade;

    // Đọc dữ liệu đầu vào
    while (1) {
        scanf("%s", name);
        if (strcmp(name, "#") == 0)
            break;
        scanf("%f", &grade);
        if (grade >= 0.0 && grade <= 10.0) {
            append(&head, name, grade);
        }
    }

    // Sắp xếp và in danh sách
    head = mergeSort(head);
    printList(head);
    freeList(head);

    return 0;
}

Node* createNode(char* name, float grade)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->grade = grade;
    newNode->previous = newNode->next = NULL;
    return newNode;
}

void append(Node** head, char* name, float grade)
{
    Node* newNode = createNode(name, grade);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->previous = temp;
}

void printList(Node* node)
{
    while (node != NULL) {
        printf("%s ", node->name);
        node = node->next;
    }
    printf("\n");
}

void freeList(Node* node)
{
    while (node != NULL) {
        Node* temp = node;
        node = node->next;
        free(temp);
    }
}

// Tách danh sách thành hai phần
void splitList(Node* source, Node** frontRef, Node** backRef)
{
    Node* fast;
    Node* slow;
    slow = source;
    fast = source->next;

    // 'fast' di chuyển hai bước và 'slow' di chuyển một bước
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    // 'slow' là điểm giữa danh sách
    *frontRef = source;
    *backRef = slow->next;
    slow->next = NULL;
}

// Hợp nhất hai danh sách đã sắp xếp
Node* merge(Node* first, Node* second)
{
    if (!first)
        return second;
    if (!second)
        return first;

    // Chọn node nhỏ hơn và tiếp tục hợp nhất
    if (first->grade <= second->grade) {
        first->next = merge(first->next, second);
        first->next->previous = first;
        first->previous = NULL;
        return first;
    } else {
        second->next = merge(first, second->next);
        second->next->previous = second;
        second->previous = NULL;
        return second;
    }
}

// Hàm Merge Sort
Node* mergeSort(Node* head)
{
    if (!head || !head->next)
        return head;

    Node* first;
    Node* second;

    // Tách danh sách thành hai nửa
    splitList(head, &first, &second);

    // Gọi đệ quy cho hai nửa
    first = mergeSort(first);
    second = mergeSort(second);

    // Hợp nhất hai nửa đã được sắp xếp
    return merge(first, second);
}
