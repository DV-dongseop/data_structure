#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#define max(a,b)  (((a)>(b))? (a):(b))

typedef struct TreeNode {
	int data;
	struct TreeNode *left, *right;
} TreeNode;

void node_plus_one(TreeNode *node){
    
    //1. 트리를 순회한다.
    if(node ==NULL)
        return;
    //2. 순회하면서 data값에 도착울 했을 때 +1을 한다.
    node_plus_one(node->left); // left값을 찾는다.
    node_plus_one(node->right); // right값을 찾는다.
    node->data++;
    //3. 끝.
}

void preorder(TreeNode *root) {     
	if (root != NULL) {
		printf("[%d] ", root->data);  //전위순회니깐 프린트위치 맨 위.
		preorder(root->left);
		preorder(root->right);
	}
}


int main(void)
{
    TreeNode *n1, *n2, *n3, *n4, *n5, *n6;
    n1=(TreeNode *)malloc(sizeof(TreeNode));
    n2=(TreeNode *)malloc(sizeof(TreeNode));
    n3=(TreeNode *)malloc(sizeof(TreeNode));
    n4=(TreeNode *)malloc(sizeof(TreeNode));
    n5=(TreeNode *)malloc(sizeof(TreeNode));
    n6=(TreeNode *)malloc(sizeof(TreeNode));
   
    n1->data = 15;
    n1->left=n2;
    n1->right=n3;

    n2->data = 4;
    n2->left =NULL;
    n2->right =NULL;

    n3->data= 20;
    n3->left= n4;
    n3->right= n5;

    n4->data =18;
    n4->left= n6;
    n4->right = NULL;

    n5->data=25;
    n5->left=NULL;
    n5->right= NULL;

    n6->data=16;
    n6->left=NULL;
    n6->right= NULL;

    TreeNode *root = n1; 

  preorder(root);
  node_plus_one(root);
  printf("\n");
  preorder(root);
  

}