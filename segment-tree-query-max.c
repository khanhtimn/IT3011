/*
Problem: Segment Tree Simulation - query Max
Description
Given a sequence of positive integers a1, a2, . . ., an. Perform a sequence of actions of following types:

    update  i  v : assign ai = v
    get-max  i  j : return the maximum value of the subsequence ai, ai+1, . . ., aj


Input

    Line 1: contains a positive integer n (1 <= n <= 100000)
    Line 2: contains a1, a2, . . ., an. (1 <= ai <= 10000)
    Line 3: contains a positive integer m (1 <= m <= 100000) which is the number of actions
    Line i + 3 (i = 1, 2, . . ., m): contains an action described above

Output

    Write in each line the result of the corresponding action of type get-max

Example
Input
10
1 10 9 7 1 4 2 4 8 10
5
get-max 5 8
get-max 5 9
get-max 3 8
update 9 20
get-max 4 10

Ouput
4
8
9
20
*/
#include <math.h>
#include <stdio.h>

// Function to compute the size of the segment tree
int calculateSize(int n)
{
    int x = (int)ceil(log2(n));
    return 2 * (int)pow(2, x) - 1;
}

// Function to build the segment tree
void buildTree(int arr[], int tree[], int index, int left, int right)
{
    if (left == right) {
        tree[index] = arr[left];
        return;
    }

    int mid = left + (right - left) / 2;
    buildTree(arr, tree, 2 * index + 1, left, mid);
    buildTree(arr, tree, 2 * index + 2, mid + 1, right);
    tree[index] = (tree[2 * index + 1] > tree[2 * index + 2]) ? tree[2 * index + 1] : tree[2 * index + 2];
}

// Function to update a value in the segment tree
void update(int arr[], int tree[], int index, int left, int right, int i, int newValue)
{
    if (left == right && left == i) {
        arr[i] = newValue;
        tree[index] = newValue;
        return;
    }

    if (i < left || i > right)
        return;

    int mid = left + (right - left) / 2;
    update(arr, tree, 2 * index + 1, left, mid, i, newValue);
    update(arr, tree, 2 * index + 2, mid + 1, right, i, newValue);
    tree[index] = (tree[2 * index + 1] > tree[2 * index + 2]) ? tree[2 * index + 1] : tree[2 * index + 2];
}

// Function to query maximum value in a range
int query(int tree[], int index, int left, int right, int qLeft, int qRight)
{
    if (qLeft <= left && qRight >= right) // Total overlap
        return tree[index];

    if (qRight < left || qLeft > right) // No overlap
        return -1;

    int mid = left + (right - left) / 2;
    int leftMax = query(tree, 2 * index + 1, left, mid, qLeft, qRight);
    int rightMax = query(tree, 2 * index + 2, mid + 1, right, qLeft, qRight);

    if (leftMax == -1)
        return rightMax;
    if (rightMax == -1)
        return leftMax;

    return (leftMax > rightMax) ? leftMax : rightMax;
}

int main()
{
    int n, m;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int treeSize = calculateSize(n);
    int tree[treeSize];

    buildTree(arr, tree, 0, 0, n - 1);

    scanf("%d", &m);

    for (int i = 0; i < m; i++) {
        char action[10];
        int a, b;
        scanf("%s %d %d", action, &a, &b);

        if (action[0] == 'u') { // update
            update(arr, tree, 0, 0, n - 1, a - 1, b);
        } else if (action[0] == 'g') { // get-max
            int result = query(tree, 0, 0, n - 1, a - 1, b - 1);
            printf("%d\n", result);
        }
    }

    return 0;
}
