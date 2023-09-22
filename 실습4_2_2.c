#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define max(a,b)  (((a)>(b))? (a):(b))

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;



int get_node_count(TreeNode *node)
{
    int count =0;

    if(node!=NULL)
        count=1+get_node_count(node->left) +
        get_node_count(node->right);
    
    return count;
}

int get_leaf_count(TreeNode *node)
{
    int count =0;

    if(node != NULL){
        if(node->left == NULL && node ->right==NULL)
        return 1;
    else
        count = get_leaf_count(node->left) + get_leaf_count(node->right);
    }
    return count;

}

int get_height(TreeNode *node)
{
    int height = 0;

    if(node != NULL)
        height = 1 + max(get_height(node->left),
        get_height(node->right));

    return height;
}

void isBalanced(TreeNode* node)
{
	
	int left_height = get_height(node->left);
	int right_height = get_height(node->right);
   
	int height;

    if(left_height>right_height)
        height= left_height- right_height;
    else
        height= right_height- left_height;

	if (height <= 1 && height >= -1) 
        printf("균형트리입니다.");
	else 
        printf("균형트리가 아닙니다.");
}

int main(void)
{
    TreeNode *n1, *n2, *n3, *n4, *n5, *n6, *n7;
    n1=(TreeNode *)malloc(sizeof(TreeNode));
    n2=(TreeNode *)malloc(sizeof(TreeNode));
    n3=(TreeNode *)malloc(sizeof(TreeNode));
    n4=(TreeNode *)malloc(sizeof(TreeNode));
    n5=(TreeNode *)malloc(sizeof(TreeNode));
    n6=(TreeNode *)malloc(sizeof(TreeNode));
    n7=(TreeNode *)malloc(sizeof(TreeNode));


    n1->data = 15;
    n1->left=n2;
    n1->right=n4;

    n2->data = 4;
    n2->left =n3;
    n2->right =NULL;

    n3->data=1;
    n3->left =NULL;
    n3->right= NULL;

    n4->data= 20;
    n4->left= n5;
    n4->right= n6;

    n5->data =18;
    n5->left= n7;
    n5->right = NULL;

    n6->data=25;
    n6->left=NULL;
    n6->right= NULL;

    n7->data=16;
    n7->left=NULL;
    n7->right= NULL;

    TreeNode *root = n1; 

   
    isBalanced(root);

}