/*Problem: Check if a given binary tree is a BST
Description
Each node of a binary tree has a field key which is the key of the node. Build a binary tree and check if the tree is a binary search tree (BST), and compute the sum of keys of nodes of the given tree (keys of the nodes are distinct and in the range 1, 2, …, 105)
Input
•Line 1 contains MakeRoot u: make the root of the tree having id = u
•Each subsequent line contains: AddLeft or AddRightcommands with the format
•AddLeft u v: create a node having id = u, add this node as a left-child of the node with id = v (if not exists)
•AddRight u v: create a node having id = u, add this node as a right-child of the node with id = v (if not exists)
•The last line contains * which marks the end of the input
Output
•Write two integers z and s in which s is the sum of keys of nodes of the tree and z = 1 if the tree is a BST and z = 0, otherwise
Example
Input
MakeRoot 4
AddRight 5 4
AddLeft 3 4
AddRight 8 5
AddLeft 1 3
AddLeft 7 8
AddLeft 6 7
AddRight 2 1
AddRight 10 8
AddLeft 9 10
*
Output
1 55
*/
#include <iostream>
#include <map>
#include <stack>
using namespace std;

// Define the structure of a tree node
struct Node {
    int key;
    Node *left, *right;
    Node(int k)
        : key(k)
        , left(nullptr)
        , right(nullptr)
    {
    }
};

// Function to check if a binary tree is a BST
bool isBSTUtil(Node* node, int min, int max)
{
    if (node == nullptr)
        return true;
    if (node->key < min || node->key > max)
        return false;
    return isBSTUtil(node->left, min, node->key - 1) && isBSTUtil(node->right, node->key + 1, max);
}

bool isBST(Node* root)
{
    return isBSTUtil(root, 1, 100000);
}

// Function to calculate the sum of all keys in the tree
int sumOfKeys(Node* root)
{
    if (root == nullptr)
        return 0;

    std::stack<Node*> stack;
    stack.push(root);

    int sum = 0;
    while (!stack.empty()) {
        Node* node = stack.top();
        stack.pop();

        sum += node->key;

        if (node->right != nullptr) {
            stack.push(node->right);
        }
        if (node->left != nullptr) {
            stack.push(node->left);
        }
    }

    return sum;
}

long long sumOfKeysIterative(Node* root)
{
    if (root == nullptr)
        return 0;

    std::stack<Node*> stack;
    stack.push(root);

    long long sum = 0;
    while (!stack.empty()) {
        Node* node = stack.top();
        stack.pop();

        sum += node->key;

        if (node->right != nullptr) {
            stack.push(node->right);
        }
        if (node->left != nullptr) {
            stack.push(node->left);
        }
    }

    return sum;
}

int main()
{
    map<int, Node*> nodes;
    string command;
    int u, v;
    Node* root = nullptr;

    while (cin >> command && command != "*") {
        if (command == "MakeRoot") {
            cin >> u;
            root = new Node(u);
            nodes[u] = root;
        } else if (command == "AddLeft" || command == "AddRight") {
            cin >> u >> v;
            if (nodes.find(v) == nodes.end())
                continue;

            nodes[u] = new Node(u);
            if (command == "AddLeft") {
                nodes[v]->left = nodes[u];
            } else {
                nodes[v]->right = nodes[u];
            }
        }
    }

    int isBSTFlag = isBST(root) ? 1 : 0;
    long long sum = sumOfKeysIterative(root);

    cout << isBSTFlag << " " << sum << endl;

    return 0;
}
