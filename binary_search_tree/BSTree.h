#pragma once

class BSTree {
private:
    class Node {
        public:
            int value;
            Node* left = nullptr;
            Node* right = nullptr;

            Node(int val) {  this->value = val;}

    };

    Node* root = nullptr;
    void insert(Node*& root, int value);
public:
    void insert(int value);
    int knotsCount(Node* root);
    Node* getRoot() { return this->root; }
    void sortedPrint(Node* root);
};