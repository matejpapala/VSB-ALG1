#include "BSTree.h"
#include <iostream>
using namespace std;

void BSTree::insert(int value) {
    this->insert(this->root, value);
}

void BSTree::insert(Node*& root, int value) {
    if(root == nullptr) {
        root = new Node(value);
        return;
    }
    if(value < root->value) {
        insert(root->left, value);
    }
    if(value > root->value) {
        insert(root->right, value);
    }
}

int BSTree::knotsCount(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    return 1 + knotsCount(root->left) + knotsCount(root->right);
}

void BSTree::sortedPrint(Node* root) {
    if(root == nullptr) {
        return;
    }
    sortedPrint(root->left);
    cout << root->value << " ";
    sortedPrint(root->right);
}

int BSTree::treeHeight(Node* root) {
    if(root == nullptr) {
        return 0;
    }
    return 1 + max(treeHeight(root->left), treeHeight(root->right));
}

bool BSTree::isBalanced(Node* root) {
    if(root == nullptr) {
        return true;
    }
    int leftHeight = treeHeight(root->left);
    int rightHeight = treeHeight(root->right);
    return abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}