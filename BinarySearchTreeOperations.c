#include<stdio.h>
#include<stdlib.h>
struct BSTNode
{
    struct BSTNode *left;
    int data;
    struct BSTNode *right;
};
struct BSTNode *root = NULL; //Empty tree [without any nodes]
void inOrderBST(struct BSTNode*);
struct BSTNode* prepareNewNode(int value)
{
    struct BSTNode *newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode)); 
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct BSTNode* BSTInsertionR(struct BSTNode *rootNode,int value)
{
    if(rootNode == NULL)            return prepareNewNode(value);
    if(value < rootNode->data)      rootNode->left = BSTInsertionR(rootNode->left, value);
    else                            rootNode->right = BSTInsertionR(root->right, value);
}

struct BSTNode* BSTInsertion(struct BSTNode *rootNode,int value)
{
    struct BSTNode *newNode = prepareNewNode(value);
    if(rootNode == NULL)    return newNode;
    else
    {
        struct BSTNode *ptr = rootNode;
        while(ptr != NULL)
        {
            if(value < ptr->data)//Insert data into leftside
            {
                if(ptr->left == NULL)
                {
                    ptr->left = newNode;
                    break;
                }
                else
                    ptr = ptr->left;
            }
            else //Insert data into rightside
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
        return rootNode;
    }
}
//Rule: If you traverse BST in in-order all elements will be displayed in ascending order
void inOrderBST(struct BSTNode *rootNode)
{
    if(rootNode)
    {
        inOrderBST(rootNode->left);
        printf("%d ",rootNode->data);
        inOrderBST(rootNode->right);
    }
}

struct BSTNode* BSTDeletion(struct BSTNode *rootNode,int value)
{
    if(rootNode == NULL)                return root;
    if(value < rootNode->data)          rootNode->left = BSTDeletion(root->left,value);
    else if(value > rootNode->data)     rootNode->right = BSTDeletion(rootNode->right,value);
    else
    {
        struct BSTNode *ptr;
        if(rootNode->left && rootNode->right)
        {
            ptr = rootNode->left;
            while(ptr->right)    //Identifying maximum value in leftside of root
                ptr = ptr->right; 
            rootNode->data = ptr->data;
            rootNode->left = BSTDeletion(rootNode->left, ptr->data);
        }
        else
        {
            ptr = rootNode;
            if(rootNode->left == NULL)          rootNode = rootNode->right;
            else if(rootNode->right == NULL)    rootNode = rootNode->left;
            free(ptr);
        }
        return rootNode;
    }
}

struct BSTNode* searchBSTElement(struct BSTNode *rootNode,int value)
{
    if(rootNode == NULL)    return NULL;
    struct BSTNode *ptr = rootNode;
    while(ptr!=NULL)//ptr
    {
        if(value == ptr->data)      return ptr;
        else if(value < ptr->data)  ptr = ptr->left;
        else                        ptr = ptr->right; 
    }
    return NULL;
}

int getMax(struct BSTNode *rootNode)
{
    if(rootNode == NULL)    return -1;
    struct BSTNode *ptr = rootNode;
    while(ptr->right)
        ptr = ptr->right;
    return ptr->data;
}

int getMin(struct BSTNode *rootNode)
{
    if(rootNode == NULL)    return -1;
    struct BSTNode *ptr = rootNode;
    while(ptr->left)
        ptr = ptr->left;
    return ptr->data;
}

int main()
{
    int n,i,newNodeValue;
    printf("With how many nodes you want to construct a BST? Answer: ");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        printf("Enter new node value: ");
        scanf("%d",&newNodeValue);
        root = BSTInsertion(root,newNodeValue);
    }
    inOrderBST(root);
    printf("\nWhich node you want to delete? Answer: ");
    scanf("%d",&newNodeValue);
    root = BSTDeletion(root,newNodeValue);
    inOrderBST(root);
    printf("\nFor which node you want to search? Answer: ");
    scanf("%d",&newNodeValue);
    if(searchBSTElement(root,newNodeValue) == NULL)     printf("Element was not found");
    else                                                printf("Element was found");
    int result = getMax(root);
    if(result == -1)      printf("\nBS Tree is empty");
    else                  printf("\nMaximum value: %d",result);
    result = getMin(root);
    if(result == -1)      printf("\nBS Tree is empty");
    else                  printf("\nMinimum value: %d",result);
    return 0;
}