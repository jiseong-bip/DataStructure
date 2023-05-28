//
//  main.c
//  treeOrder
//
//  Created by 전지성 on 2023/05/01.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
}TreeNode;

TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 20, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

void inorder(TreeNode* root) {
    if (root != NULL) {
        inorder(root->left);// 왼쪽서브트리 순회
        printf("[%d] ", root->data);  // 노드 방문
        inorder(root->right);// 오른쪽서브트리 순회
    }
}

void preOrder(TreeNode* root){
    if(root!=NULL) {
        printf("[%d]", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void postOrder(TreeNode* root) {
    if(root!=NULL){
        postOrder(root->left);
        postOrder(root->right);
        printf("[%d]", root->data);
    }
}



int main(int argc, const char * argv[]) {
    // insert code here...
    printf("중위 순회=");
    inorder(root);
    printf("\n");

    printf("전위 순회=");
    preOrder(root);
    printf("\n");

    printf("후위 순회=");
    postOrder(root);
    printf("\n");
    return 0;

}
