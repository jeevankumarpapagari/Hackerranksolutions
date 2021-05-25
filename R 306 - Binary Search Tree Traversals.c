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

void  preOrder(struct BSTNode *root)
{
    if(root)
    {
        printf("%d ",root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct BSTNode *root)
{
    if(root)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

void postOrder(struct BSTNode *root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ",root->data);
    }
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
    preOrder(root);
    printf("\n");
    inOrder(root);
    printf("\n");
    postOrder(root);
    return 0;
}
