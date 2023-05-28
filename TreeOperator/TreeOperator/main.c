//
//  main.c
//  TreeOperator
//
//  Created by 전지성 on 2023/05/02.
//

#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct TreeNode {
    int data;
    struct TreeNode *left, *right;
} TreeNode;

//        +
//    *        +
//  1   4   16   25
TreeNode n1 = { 1,  NULL, NULL };
TreeNode n2 = { 4,  NULL,  NULL };
TreeNode n3 = { '*',  &n1,  &n2 };
TreeNode n4 = { 16, NULL, NULL };
TreeNode n5 = { 25, NULL, NULL };
TreeNode n6 = { '+', &n4,  &n5 };
TreeNode n7 = { '+', &n3,  &n6 };
TreeNode* expr = &n7;

int evaluate(TreeNode* root){
    if(root == NULL) return 0;
    if(root->left == NULL && root->right==NULL) return root->data;
    else{
        int op1 = evaluate(root->left);
        int op2 = evaluate(root->right);
        
        printf("%d %c %d 을 계산 합니다 \n", op1, root->data, op2);
        
        switch(root->data){
            case '+':
                return op1 + op2;
            case '-':
                return op1 - op2;
            case '*':
                return op1 * op2;
            case '/':
                return op1 / op2;
        }
    }
    return 0;
}

int main(int argc, const char * argv[]) {
    
    printf("수식의 값은 %d입니다. \n", evaluate(expr));

    return 0;

}
