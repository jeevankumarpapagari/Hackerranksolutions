#include <stdio.h>
#include <stdlib.h>

struct Node
{
    char data;
    struct Node *right;
    struct Node *left;
}*front = NULL, *rear = NULL;

void enq(struct Node *temproot);
struct Node *deq(void);
struct Node *newNode(char data);
void LevelOrder(struct Node *root);

int main(void)
{
    struct Node *root = newNode('A');
    root->left = newNode('B');
    root->right = newNode('C');
    root->left->left = newNode('D');
    root->left->right = newNode('E');
    root->right->left = newNode('F');
    root->right->right = newNode('G');

    LevelOrder(root);

    return 0;
}

struct Node *newNode(char x)
{
    struct Node *temp1 = (struct Node *)malloc(sizeof(struct Node));
    temp1->data = x;
    temp1->right = NULL;
    temp1->left = NULL;
    return temp1;
}

void enq(struct Node *temproot)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->right = NULL;
    temp->left = temproot;
    temp->data = 'Z';

    if (front == NULL && rear == NULL)
    {
        front = rear = temp;
    }
    else
    {
        rear->right = temp;
        rear = temp;
    }
}

struct Node *deq(void)
{
    struct Node *temp = front;
    if (front == NULL)
    {
        printf("The queue is empty!\n");
    }
    else if (rear == front)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->right;
    }
    struct Node *next = (temp == NULL) ? NULL : temp->left;
    free(temp);
    return next;
}

void LevelOrder(struct Node *root)
{
    struct Node *temproot = root;

    while (temproot != NULL)
    {
        printf("%c ", temproot->data);
        if (temproot->left != NULL)
        {
            enq(temproot->left);
        }
        if (temproot->right != NULL)
        {
            enq(temproot->right);
        }
        temproot = deq();
    }
    putchar('\n');
}
