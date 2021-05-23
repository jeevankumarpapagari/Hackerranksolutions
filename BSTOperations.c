#include<stdio.h>
#include<stdlib.h>
struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct node *root = NULL;

void inOrder(struct node *root)
{
    if(root)
    {
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}

struct node* prepareNewNode(int value)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* BSTInsertion(struct node *root, int newValue)
{
    struct node *newNode = prepareNewNode(newValue);

    if(root == NULL)    return newNode;
    else
    {
        struct node *ptr = root;
        while(ptr != NULL)
        {
            if(newValue < ptr->data)
            {
                if(ptr->left == NULL)
                {
                    ptr->left = newNode;
                    break;
                }
                else
                    ptr = ptr->left;
            }
            else
            {
                if(ptr->right == NULL)
                {
                    ptr->right = newNode;
                    break;
                }
                else
                    ptr = ptr->right;
            }
        }
        return root;
    }
}

struct node* BSTInsertionR(struct node *root, int value)
{
    if(root == NULL)        return prepareNewNode(value);
    if(value < root->data)  root->left = BSTInsertionR(root->left,value);
    else                    root->right = BSTInsertion(root->right,value);
}

struct node* deleteNode(struct node *root,int value)
{
    if(root == NULL)                return root;
    if(value < root->data)          root->left = deleteNode(root->left,value);
    else if(value > root->data)     root->right = deleteNode(root->right,value);
    else
    {
        struct node *ptr;
        if(root->left != NULL && root->right != NULL)
        {
            ptr = root;
            while(ptr->right != NULL)
                ptr = ptr->right; 
            root->data = ptr->data;
            root->left = deleteNode(root->left,ptr->data);
        }
        else
        {
            ptr = root;
            if(root->left == NULL)          root = root->right;
            else if(root->right == NULL)    root = root->left;
            free(root); 
        }
        return root;
    }
}

int main()
{
    int n,i,newValue;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter new value to insert: ");
        scanf("%d",&newValue);
        root = BSTInsertion(root,newValue);
    }
    inOrder(root);
    printf("\nWhich element you want to delete? Answer: ");
    scanf("%d",&newValue);
    root = deleteNode(root,newValue);
    inOrder(root);
    return 0;
}