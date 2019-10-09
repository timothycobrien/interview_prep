#include <iostream>
#include <string>

using namespace std;

struct Node {
    string value;
    Node *left;
    Node *right;

    Node(string val) {
        value = val;
        left = nullptr;
        right = nullptr;
    }
};

void inOrderTraversal(Node *root) {
    if (root == nullptr)
        return;
    inOrderTraversal(root->left);
    cout << root->value << endl;
    inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root) {
    if (root == nullptr)
        return;
    cout << root->value << endl;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root) {
    if (root == nullptr)
        return;
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->value << endl;
}

void traversalTest() {
    Node *root = new Node("1");
    root->left = new Node("2");
    root->right = new Node("3");
    root->left->left = new Node("4");
    root->left->right = new Node("5");

    cout << "In order" << endl;
    inOrderTraversal(root);

    cout << "Pre order" << endl;
    preOrderTraversal(root);

    cout << "Post order" << endl;
    postOrderTraversal(root);
}

/*
int main() {
    traversalTest();
    return 0;
}*/
