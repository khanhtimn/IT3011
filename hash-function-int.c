/*
Problem: Hash Over Integers
Description
A database contains a sequence of key k1, k2, ..., kn which are integers (1<=n<=100000). Perform a sequence of actions of two kinds:
· find k: find and return 1 if k exists in the database, and return 0, otherwise
· insert k: insert a key k into the database and return 1 if the insertion is successful (k does not exist in the database) and return 0 if the insertion is failed (k exists in the database)
Note that the value of any key is greater than or equal to 0 and less than or equal to 1017.
Input
Two blocks of information. The first block contains a key of (k1,k2,...,kn) in each line. The first block is terminated with a line containing *. The second block is a sequence of actions of two finds described above: each line contains 2 string: cmd and k in which cmd = "find" or "insert" and k is the key (parameter of the action). The second block is terminated with a line containing ***. Note that the number of actions can be up to 100000.
Output
Each line contains the result (0 or 1) of the corresponding action.
Example
Input
4
5
2
*
find 3
insert 4
find 2
insert 3
find 3
***
Output
0
0
1
1
1
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEYS 100000
#define HASH_SIZE 100003 // A prime number as hash table size

typedef struct Node {
    long key;
    struct Node* next;
} Node;

Node* hashTable[HASH_SIZE];

unsigned long hash(long key)
{
    return key % HASH_SIZE;
}

Node* createNode(long key)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode) {
        newNode->key = key;
        newNode->next = NULL;
    }
    return newNode;
}

int insert(long key)
{
    unsigned long index = hash(key);
    Node* current = hashTable[index];

    // Check if key already exists
    while (current) {
        if (current->key == key) {
            return 0; // Key already exists
        }
        current = current->next;
    }

    // Insert new key
    Node* newNode = createNode(key);
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    return 1;
}

int find(long key)
{
    unsigned long index = hash(key);
    Node* current = hashTable[index];

    while (current) {
        if (current->key == key) {
            return 1; // Key found
        }
        current = current->next;
    }

    return 0; // Key not found
}

int main()
{
    long key;
    char cmd[10];

    // Initialize hash table
    memset(hashTable, 0, sizeof(hashTable));

    // Read initial keys
    while (scanf("%ld", &key) && key != -1) {
        insert(key);
    }

    // Perform actions
    while (scanf("%s %ld", cmd, &key)) {
        if (strcmp(cmd, "***") == 0) {
            break;
        }

        if (strcmp(cmd, "find") == 0) {
            printf("%d\n", find(key));
        } else if (strcmp(cmd, "insert") == 0) {
            printf("%d\n", insert(key));
        }
    }

    return 0;
}
