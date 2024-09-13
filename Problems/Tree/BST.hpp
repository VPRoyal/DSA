#ifndef BST_HPP
#define BST_HPP

#include <iostream>

namespace BST {
    struct Node {
        int data;
        Node* left;
        Node* right;
    };

    Node* createNode(int data);
    void insertNode(Node* &root, int data);
    Node* createBST(int datasets[], int dataSize);
    void inorderTraversal(Node* root);
    void preOrderTraversal(Node* root);
    void postOrderTraversal(Node* root);
    void levelOrderTraversal(Node* root);
}

#endif // BinarySeartchTree_HPP