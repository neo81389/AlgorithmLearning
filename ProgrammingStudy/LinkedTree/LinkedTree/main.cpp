//
//  main.cpp
//  LinkedTree
//
//  Created by Joonhee Lee on 2019/10/10.
//  Copyright © 2019 Joonhee Lee. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    int data;
    struct TreeNode *left, *right;
} TreeNode;

int main() {
    
    TreeNode *n1, *n2, *n3;
    
    n1 = (TreeNode*)malloc(sizeof(TreeNode));
    n2 = (TreeNode*)malloc(sizeof(TreeNode));
    n3 = (TreeNode*)malloc(sizeof(TreeNode));
    
    n1 -> data = 10;
    n1 -> left = n2;
    n1 -> right = n3;
    
    n2 -> data = 20;
    n2 -> left = NULL;
    n2 -> right = NULL;
    
    n3 -> data = 30;
    n3 -> left = NULL;
    n3 -> right = NULL;
    
    printf("n1 has data which is %d\n", n1 -> data);
    printf("what data is on the left sidee of n1 : %d\n", n1 -> left -> data);
    printf("what data is on the right sidee of n1 : %d\n\n", n1 -> right -> data);
    
    printf("what data is on the left sidee of n1 : %p\n", n1 -> left);
    printf("what data is on the right sidee of n1 : %p\n\n", n1 -> right);
    
    printf("what's on the left side of n2 : %p\n", n2 -> left);
    printf("what's on the right side of n2 : %p\n", n2 -> right);
    
    printf("what's on the left side of n3 : %p\n", n3 -> left);
    printf("what's on the right side of n3 : %p\n", n3 -> right);
     
    
    return 0;
}
