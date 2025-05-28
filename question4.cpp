#include <iostream>
using namespace std;

// Node class for BST
class Node {
public:
    int data;
    Node *left, *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

// Binary Search Tree class
class BST {
    Node* root;

    // Helper function to insert a value
    Node* insert(Node* node, int val) {
        if (!node) return new Node(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else
            node->right = insert(node->right, val);
        return node;
    }

    // Helper function to search for a value
    bool search(Node* node, int val) {
        if (!node) return false;
        if (node->data == val) return true;
        if (val < node->data)
            return search(node->left, val);
        else
            return search(node->right, val);
    }

    // Helper function for inorder traversal
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper function for preorder traversal
    void preorder(Node* node) {
        if (!node) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }

    // Helper function for postorder traversal
    void postorder(Node* node) {
        if (!node) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }

public:
    BST() : root(nullptr) {}

    // Public insert function
    void insert(int val) { root = insert(root, val); }

    // Public search function
    bool search(int val) { return search(root, val); }

    // Public traversal functions
    void inorder() { inorder(root); cout << endl; }
    void preorder() { preorder(root); cout << endl; }
    void postorder() { postorder(root); cout << endl; }
};

int main() {
    BST tree;
    // Insert values
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);

    // Traversals
    cout << "Inorder: ";
    tree.inorder();

    cout << "Preorder: ";
    tree.preorder();

    cout << "Postorder: ";
    tree.postorder();

    // Search for a value
    int val = 7;
    cout << "Searching for " << val << ": ";
    if (tree.search(val))
        cout << "Found" << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}