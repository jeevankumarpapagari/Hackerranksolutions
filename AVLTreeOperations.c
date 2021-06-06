#include<stdio.h>
#include<stdlib.h>
struct AVLNode
{
    int data, height;
    struct AVLNode *left, *right;
}*root = NULL;

int balanceFactor(struct AVLNode* root)
{
    int leftHeight = -1, rightHeight = -1;
    if(root == NULL)    return 0;
    if(root->left)      leftHeight = root->left->height;
    if(root->right)     rightHeight = root->right->height;
    return leftHeight - rightHeight;
}

int getHeight(struct AVLNode* root)
{
    int leftHeight = -1, rightHeight = -1;
    if(root == NULL)    return -1;
    if(root->left)      leftHeight = root->left->height;
    if(root->right)     rightHeight = root->right->height;
    return leftHeight > rightHeight ? leftHeight+1 : rightHeight+1;
}

struct AVLNode* rotateLeft(struct AVLNode *root)
{
    struct AVLNode *oldRoot = root;
    struct AVLNode *rightLeft = root->right->left;
    root = oldRoot->right;
    root->left = oldRoot;
    oldRoot->right = rightLeft;
    oldRoot->height = getHeight(oldRoot);
    root->height = getHeight(root);
    return root; 
}

struct AVLNode* rotateRight(struct AVLNode *root)
{
    struct AVLNode *oldRoot = root;
    struct AVLNode *leftRight = root->left->right;
    root = oldRoot->left;
    root->right = oldRoot;
    oldRoot->left = leftRight;
    oldRoot->height = getHeight(oldRoot);
    root->height = getHeight(root);
    return root;
}

struct AVLNode* createNewNode(int value)
{
    struct AVLNode *newNode = (struct AVLNode*)malloc(sizeof(struct AVLNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    newNode->height = 0;
    return newNode;
}

struct AVLNode* AVLInsertion(struct AVLNode *root, int value)
{
    if(root == NULL)        return createNewNode(value);
    if(root->data < value)  root->right = AVLInsertion(root->right,value);
    else                    root->left = AVLInsertion(root->left,value);

    if(balanceFactor(root) == 2 && balanceFactor(root->left) == 1)      root = rotateRight(root);
    if(balanceFactor(root) == -2 && balanceFactor(root->right) == -1)   root = rotateLeft(root);
    if(balanceFactor(root) == 2 && balanceFactor(root->left) == -1)
    {
        root->left = rotateLeft(root);
        root = rotateRight(root);
    }
    if(balanceFactor(root) == -2 && balanceFactor(root->right) == 1)
    {
        root->right = rotateRight(root->right);
        root = rotateLeft(root);
    }
    return root;
}

void inOrder(struct AVLNode *root)
{
    if(root)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    int i, newValue;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&newValue);
        root = AVLInsertion(root,newValue);
    }
    inOrder(root);
}