#include <stdio.h>
#include "E:\VP\Learning\DSA\Problems\Tree\binaryTree.hpp"

int main(){
    int datasets[]={12, 47, 9, 35, 22, 41, 28, 7, 50, 19};
    int dataSize=sizeof(datasets)/sizeof(datasets[0]);
    BinaryTree::Node* root = BinaryTree::createBinaryTree(datasets,dataSize);
    printf("Inorder traversal of the constructed tree is:  ");
    BinaryTree::inorderTraversal(root);
    return 0;
}