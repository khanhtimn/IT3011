/*
Problem: Linked list
Description
Given 2 linked lists  (with id = 1 and id = 2, respectively): each node contains a non-negative integer, the nodes are sorted in ascending order (values at nodes can be equal). Consider the following querries:
- insert <list_id> <number> : is used to insert the <number> value into list_id while ensuring the ascending sort of linked_list.
For example, linked list 1 contains the following values: 1 2 7; The insert 1 5 statement is used to insert the value 5 into the linked list 1 so that the values in the linked list 1 are still sorted in ascending order. Therefore, the linked list obtained after insertion is 1 2 5 7.
- remove <list_id> <k> : is used to remove the kth value in linked list with id = <list_id>. Note: the elements in the linked list are indexed from 0, so if k = 0, it means we delete the first node.
For example, linked list 2 is containing the values: 1 2 7, the query remove 2 1 will remove the 1st element in list 2, so the linked list 2 obtained after deletion is: 1 7.
- print <list_id> :prints out the elements in the linked list with id = <list_id>
- merge : merge the two given linked lists to create a new linked list whose elements in the new linked list are still sorted by ascending valu (note: there might be nodes with the same values). Print out the new linked_list after merging.
Input:
- The first line is the values in the linked list 1, ending with the value -1.
- The second 2 is the values in the linked list 2, ending with the value -1.
- Each of next line is a query of  either insert, or remove, merge, print.
Output:
Output of the query if existing

Example:
Input:
1 3 5 8 9 -1
2 6 11 -1
insert 1 7
insert 2 5
remove 1 4
remove 2 2
print 1
print 2
merge

Output
1 3 5 7 9
2 5 11
1 2 3 5 5 7 9 11
*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert(struct Node** head, int value)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->data >= value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data < value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void removeKth(struct Node** head, int k)
{
    if (*head == NULL) {
        return;
    }

    if (k == 0) {
        struct Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    } else {
        struct Node* current = *head;
        int i = 0;
        while (i < k - 1 && current->next != NULL) {
            current = current->next;
            i++;
        }
        if (current->next != NULL) {
            struct Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        }
    }
}

void print(struct Node* head)
{
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

struct Node* mergeLists(struct Node* list1, struct Node* list2)
{
    struct Node* merged = NULL;
    struct Node** tail = &merged;

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            *tail = list1;
            list1 = list1->next;
        } else {
            *tail = list2;
            list2 = list2->next;
        }
        tail = &((*tail)->next);
    }

    if (list1 != NULL) {
        *tail = list1;
    } else {
        *tail = list2;
    }

    return merged;
}

int main()
{
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int value;

    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        insert(&list1, value);
    }

    while (1) {
        scanf("%d", &value);
        if (value == -1) {
            break;
        }
        insert(&list2, value);
    }

    char query[10];
    while (scanf("%s", query) != EOF) {
        if (query[0] == 'i') {
            int list_id, num;
            scanf("%d %d", &list_id, &num);
            if (list_id == 1) {
                insert(&list1, num);
            } else if (list_id == 2) {
                insert(&list2, num);
            }
        } else if (query[0] == 'r') {
            int list_id, k;
            scanf("%d %d", &list_id, &k);
            if (list_id == 1) {
                removeKth(&list1, k);
            } else if (list_id == 2) {
                removeKth(&list2, k);
            }
        } else if (query[0] == 'p') {
            int list_id;
            scanf("%d", &list_id);
            if (list_id == 1) {
                print(list1);
            } else if (list_id == 2) {
                print(list2);
            }
        } else if (query[0] == 'm') {
            struct Node* mergedList = mergeLists(list1, list2);
            print(mergedList);
        }
    }

    while (list1 != NULL) {
        struct Node* temp = list1;
        list1 = list1->next;
        free(temp);
    }
    while (list2 != NULL) {
        struct Node* temp = list2;
        list2 = list2->next;
        free(temp);
    }

    return 0;
}
