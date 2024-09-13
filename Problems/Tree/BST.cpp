#include <iostream>
#include <queue>
#include <set>

namespace BST{
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

Node* createBST(int datasets[], int dataSize){
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
void preOrderTraversal(Node* root){
    if(root!=nullptr){
        std::cout <<root->data<<" ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

void postOrderTraversal(Node* root){
    if(root!=nullptr){
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        std::cout << root->data<<" ";
    }
}
void levelOrderTraversal(Node* root){
    if(root==nullptr) return;
    
    std::queue <Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        std::cout << temp->data<<" ";
        q.pop();
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
}

}