#ifndef BINARYTREE_HPP
#define BINARYTREE_HPP

#include <iostream>

namespace BinaryTree {
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* createNode(int data);
    void insertNode(Node* root, int data);
    Node* createBinaryTree(int datasets[], int dataSize);
    void inorderTraversal(Node* root);
}

#endif // BINARYTREE_HPP