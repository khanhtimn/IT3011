/*
Problem: Linked List Manipulation
Description
Viết chương trình thực hiện công việc sau:
Xây dựng danh sách liên kết với các khóa được cung cấp ban đầu là dãy a1, a2, …, an, sau đó thực hiện các thao tác trên danh sách bao gồm: thêm 1 phần tử vào đầu, vào cuối danh sách, hoặc vào trước, vào sau 1 phần tử nào đó trong danh sách, hoặc loại bỏ 1 phần tử nào đó trong danh sách

Input

    Dòng 1: ghi số nguyên dương n (1 <= n <= 1000)
    Dòng 2: ghi các số nguyên dương a1, a2, …, an.
    Các dòng tiếp theo lần lượt là các lệnh để thao tác (kết thúc bởi ký hiệu #) với các loại sau:
    addlast  k: thêm phần tử có key bằng k vào cuối danh sách (nếu k chưa tồn tại)
    addfirst  k: thêm phần tử có key bằng k vào đầu danh sách (nếu k chưa tồn tại)
    addafter  u  v: thêm phần tử có key bằng u vào sau phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u chưa tồn tại)
    addbefore  u  v: thêm phần tử có key bằng  u vào trước phần tử có key bằng v trên danh sách (nếu v đã tồn tại trên danh sách và u của tồn tại)
    remove  k: loại bỏ phần tử có key bằng k khỏi danh sách
    reverse: đảo ngược thứ tự các phần tử của danh sách (không được cấp phát mới các phần tử, chỉ được thay đổi mối nối liên kết)

Output

    Ghi ra dãy khóa của danh sách thu được sau 1 chuỗi các lệnh thao tác đã cho


Example
Input
5
5 4 3 2 1
addlast 3
addlast 10
addfirst 1
addafter 10 4
remove 1
#

Output
5 4 3 2 10
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure
typedef struct Node {
    int key;
    struct Node* next;
} Node;

// Function to create a new node
Node* createNode(int key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->next = NULL;
    return newNode;
}

// Function to check if a key exists in the list
int keyExists(Node* head, int key)
{
    Node* current = head;
    while (current != NULL) {
        if (current->key == key)
            return 1;
        current = current->next;
    }
    return 0;
}

// Function to add a node at the beginning of the list
void addFirst(Node** head, int key)
{
    if (keyExists(*head, key))
        return;
    Node* newNode = createNode(key);
    newNode->next = *head;
    *head = newNode;
}

// Function to add a node at the end of the list
void addLast(Node** head, int key)
{
    if (keyExists(*head, key))
        return;
    Node* newNode = createNode(key);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to add a node after a given node
void addAfter(Node* head, int newKey, int existingKey)
{
    if (keyExists(head, newKey))
        return;
    Node* temp = head;
    while (temp != NULL && temp->key != existingKey) {
        temp = temp->next;
    }
    if (temp != NULL) {
        Node* newNode = createNode(newKey);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to add a node before a given node
void addBefore(Node** head, int newKey, int existingKey)
{
    if (keyExists(*head, newKey))
        return;
    if (*head == NULL)
        return;
    if ((*head)->key == existingKey) {
        addFirst(head, newKey);
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL && temp->next->key != existingKey) {
        temp = temp->next;
    }
    if (temp->next != NULL) {
        Node* newNode = createNode(newKey);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to remove a node from the list
void removeNode(Node** head, int key)
{
    if (!keyExists(*head, key))
        return;
    Node *temp = *head, *prev = NULL;
    if (temp != NULL && temp->key == key) {
        *head = temp->next;
        free(temp);
        return;
    }
    while (temp != NULL && temp->key != key) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL)
        return;
    prev->next = temp->next;
    free(temp);
}

// Function to reverse the list
void reverseList(Node** head)
{
    Node* prev = NULL;
    Node* current = *head;
    Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
}

// Function to print the list
void printList(Node* head)
{
    Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->key);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    Node* head = NULL;
    int n, key;
    char command[20];
    int u, v;

    // Read initial list elements
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &key);
        addLast(&head, key);
    }

    // Process commands
    while (1) {
        scanf("%s", command);
        if (strcmp(command, "#") == 0)
            break;

        if (strcmp(command, "addlast") == 0) {
            scanf("%d", &key);
            addLast(&head, key);
        } else if (strcmp(command, "addfirst") == 0) {
            scanf("%d", &key);
            addFirst(&head, key);
        } else if (strcmp(command, "addafter") == 0) {
            scanf("%d %d", &u, &v);
            addAfter(head, u, v);
        } else if (strcmp(command, "addbefore") == 0) {
            scanf("%d %d", &u, &v);
            addBefore(&head, u, v);
        } else if (strcmp(command, "remove") == 0) {
            scanf("%d", &key);
            removeNode(&head, key);
        } else if (strcmp(command, "reverse") == 0) {
            reverseList(&head);
        }
    }

    // Print the final list
    printList(head);

    return 0;
}
