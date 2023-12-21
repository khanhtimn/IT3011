#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *next;
} Node;

// Function to insert a new node at the end of the list
void insertEnd(Node **head, int value) {
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->data = value;
  newNode->next = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    Node *temp = *head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    temp->next = newNode;
  }
}

// Function to reverse the linked list
Node *reverseList(Node *head) {
  Node *prev = NULL, *current = head, *next = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  return prev;
}

// Function to compare two linked lists
bool compareLists(Node *head1, Node *head2) {
  Node *temp1 = head1;
  Node *temp2 = head2;

  while (temp1 && temp2) {
    if (temp1->data == temp2->data) {
      temp1 = temp1->next;
      temp2 = temp2->next;
    } else {
      return false;
    }
  }

  // If both are null, lists are identical
  if (temp1 == NULL && temp2 == NULL) {
    return true;
  }

  // If lists are of different sizes
  return false;
}

// Function to check if a linked list is a palindrome
bool isPalindrome(Node *head) {
  if (head == NULL || head->next == NULL)
    return true;

  Node *slow = head, *fast = head, *prev_slow = head;
  Node *second_half, *midnode = NULL;
  bool res = true;

  while (fast != NULL && fast->next != NULL) {
    fast = fast->next->next;
    prev_slow = slow;
    slow = slow->next;
  }

  if (fast != NULL) {
    midnode = slow;
    slow = slow->next;
  }

  second_half = slow;
  prev_slow->next = NULL;
  second_half = reverseList(second_half);

  res = compareLists(head, second_half);

  second_half = reverseList(second_half);
  if (midnode != NULL) {
    prev_slow->next = midnode;
    midnode->next = second_half;
  } else {
    prev_slow->next = second_half;
  }

  return res;
}

int main() {
  int n, val;
  Node *head = NULL;

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &val);
    insertEnd(&head, val);
  }

  if (isPalindrome(head)) {
    printf("1\n");
  } else {
    printf("0\n");
  }

  return 0;
}
