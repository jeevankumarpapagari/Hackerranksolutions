#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct BSTNode
{
    struct BSTNode *left;
    int data;
    struct BSTNode *right;
};
struct BSTNode *root = NULL;

struct BSTNode* prepareNewNode(int value)
{
    struct BSTNode *newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BSTNode* BSTInsertion(struct BSTNode *root,int value)
{
    if(root == NULL)        return prepareNewNode(value);
    if(value <= root->data)  root->left = BSTInsertion(root->left,value);
    else                    root->right = BSTInsertion(root->right,value);
    return root;
}

int heightOfBST(struct BSTNode *root)
{
    if(root == NULL)    return 0;
    int lstHeight = heightOfBST(root->left);
    int rstHeight = heightOfBST(root->right);
    if(lstHeight >= rstHeight)      return lstHeight+1;
    else                            return rstHeight+1;
}

int main() 
{
    int n;
    scanf("%d",&n);
    int value,i;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&value);
        root = BSTInsertion(root,value);
    }
    printf("%d",heightOfBST(root));
    return 0;
}