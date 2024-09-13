#include <iostream>

namespace BinaryTree{
struct  Node
{
    int data;
    Node* left;
    Node* right;
};
Node* createNode(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}
void insertNode(Node* &root, int data){
    if(root==nullptr) root=createNode(data);
    else if(data<=root->data) insertNode(root->left, data);
    else insertNode(root->right, data);
}

Node* createBinaryTree(int datasets[], int dataSize){
    Node* root = nullptr;
    for(int i=0;i<dataSize;i++){
        insertNode(root, datasets[i]);
    }
    return root;
}

void inorderTraversal(Node* root){
    if(root!=nullptr){
        inorderTraversal(root->left);
        std::cout <<root->data<<" ";
        inorderTraversal(root->right);
    }
}


}