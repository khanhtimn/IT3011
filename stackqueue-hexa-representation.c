/*
Problem: Biểu diễn Hexa
Description
Cho cấu trúc và các con trỏ sau:
typedef struct Node {
char value;
struct Node* prev;
struct Node* next;
} Node;
Node* top;  // for stack
Node* head; // for queue
Node* tail; // for queue
Hãy xây dựng ngăn xếp và hàng đợi để chuyển một số ở hệ thập phân sang hệ thập lục phân.
Ví dụ:
Input:
147.625
Output:
93.A
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char value;
    struct Node* prev;
    struct Node* next;
} Node;

Node* top = NULL; // for stack
Node* head = NULL; // for queue
Node* tail = NULL; // for queue

// Hàm đẩy phần tử vào ngăn xếp
void push(char val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = val;
    newNode->next = top;
    newNode->prev = NULL;

    if (top != NULL) {
        top->prev = newNode;
    }

    top = newNode;
}

// Hàm lấy phần tử từ ngăn xếp
char pop()
{
    if (top == NULL) {
        return '\0'; // Ngăn xếp rỗng
    }

    char val = top->value;
    Node* temp = top;
    top = top->next;
    free(temp);

    if (top != NULL) {
        top->prev = NULL;
    }

    return val;
}

// Hàm đưa phần tử vào hàng đợi (queue)
void enqueue(char val)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = val;
    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Hàm lấy phần tử từ hàng đợi (queue)
char dequeue()
{
    if (head == NULL) {
        return '\0'; // Hàng đợi rỗng
    }

    char val = head->value;
    Node* temp = head;
    head = head->next;
    free(temp);

    if (head != NULL) {
        head->prev = NULL;
    }

    return val;
}

// Hàm chuyển số từ hệ thập phân sang hệ thập lục phân
void decimalToHex(double decimal)
{
    int intPart = (int)decimal;
    double fracPart = decimal - intPart;

    // Chuyển phần nguyên sang hệ thập lục phân
    while (intPart > 0) {
        int remainder = intPart % 16;
        char hexDigit;
        if (remainder < 10) {
            hexDigit = '0' + remainder;
        } else {
            hexDigit = 'A' + remainder - 10;
        }
        push(hexDigit);
        intPart /= 16;
    }

    // In phần nguyên
    printf("Output: ");
    while (top != NULL) {
        printf("%c", pop());
    }

    // In dấu thập phân
    printf(".");

    // Chuyển phần thập phân sang hệ thập lục phân
    while (fracPart > 0) {
        fracPart *= 16;
        int digit = (int)fracPart;
        char hexDigit;
        if (digit < 10) {
            hexDigit = '0' + digit;
        } else {
            hexDigit = 'A' + digit - 10;
        }
        enqueue(hexDigit);
        fracPart -= digit;
    }

    // In phần thập phân
    while (head != NULL) {
        printf("%c", dequeue());
    }

    printf("\n");
}

int main()
{
    double decimal;
    printf("Input: ");
    scanf("%lf", &decimal);
    decimalToHex(decimal);
    return 0;
}
