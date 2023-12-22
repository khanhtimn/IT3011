/*
Problem: Store & Search String
Description
A database contains a sequence of key k1, k2, ..., kn which are strings (1<=n<=100000). Perform a sequence of actions of two kinds:
· find k: find and return 1 if k exists in the database, and return 0, otherwise
· insert k: insert a key k into the database and return 1 if the insertion is successful (k does not exist in the database) and return 0 if the insertion is failed (k exists in the database)
Note that the length of any key is greater than 0 and less than or equal to 50.
Input
Two blocks of information. The first block contains a key of (k1,k2,...,kn) in each line. The first block is terminated with a line containing *. The second block is a sequence of actions of two finds described above: each line contains 2 string: cmd and k in which cmd = find or insert and k is the key (parameter of the action). The second block is terminated with a line containing ***. Note that the number of actions can be up to 100000.
Output
Each line contains the result (0 or 1) of the corresponding action.
Example
Input
computer
university
school
technology
phone
*
find school
find book
insert book
find algorithm
find book
insert book
***
Output
1
0
1
0
1
0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50
#define TABLE_SIZE 100003 // A prime number for better distribution

// Node for the linked list (chaining)
typedef struct node {
    char key[MAX_LEN + 1];
    struct node* next;
} Node;

// Hash table
Node* hashTable[TABLE_SIZE];

// Hash function to convert a string to an index
unsigned int hash(char* str)
{
    unsigned int value = 0;
    for (int i = 0; str[i]; i++) {
        value = value * 37 + str[i];
    }
    return value % TABLE_SIZE;
}

// Insert a key into the hash table
int insert(char* key)
{
    int index = hash(key);
    Node* newNode = malloc(sizeof(Node));
    if (!newNode)
        return 0;

    strcpy(newNode->key, key);
    newNode->next = NULL;

    // Check for duplicates and insert
    Node* temp = hashTable[index];
    while (temp) {
        if (strcmp(temp->key, key) == 0) {
            free(newNode);
            return 0; // Key already exists
        }
        temp = temp->next;
    }

    // Insert at the beginning of the list
    newNode->next = hashTable[index];
    hashTable[index] = newNode;
    return 1;
}

// Find a key in the hash table
int find(char* key)
{
    int index = hash(key);
    Node* temp = hashTable[index];
    while (temp) {
        if (strcmp(temp->key, key) == 0)
            return 1; // Key found
        temp = temp->next;
    }
    return 0; // Key not found
}

int main()
{
    char key[MAX_LEN + 1];
    char cmd[10];

    // Initialize hash table
    memset(hashTable, 0, sizeof(hashTable));

    // Read initial keys
    while (scanf("%s", key), strcmp(key, "*") != 0) {
        insert(key);
    }

    // Process commands
    while (scanf("%s %s", cmd, key), strcmp(cmd, "***") != 0) {
        if (strcmp(cmd, "find") == 0) {
            printf("%d\n", find(key));
        } else if (strcmp(cmd, "insert") == 0) {
            printf("%d\n", insert(key));
        }
    }

    return 0;
}
