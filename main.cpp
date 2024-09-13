#include <stdio.h>
#include "E:\VP\Learning\DSA\Problems\Tree\BST.hpp"

int main(){
    int datasets[]={12, 47, 9, 35, 22, 41, 28, 7, 50, 19};
    int dataSize=sizeof(datasets)/sizeof(datasets[0]);
    BST::Node* root = BST::createBST(datasets,dataSize);
    printf("Inorder traversal of the constructed tree is:  ");
    BST::inorderTraversal(root);
    printf("\npreOrder traversal of the constructed tree is:  ");
    BST::preOrderTraversal(root);
    printf("\npostOrder traversal of the constructed tree is:  ");
    BST::postOrderTraversal(root);
    printf("\nlevelOrder traversal of the constructed tree is:  ");
    BST::levelOrderTraversal(root);
    return 0;
}