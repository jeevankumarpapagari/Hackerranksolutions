#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

void print(struct node *head)
{
    if(head == NULL)    return;
    else
    {
        struct node *ptr = head;
        while(ptr->next!=NULL)
        {
            printf("%d->",ptr->data);
            ptr = ptr->next;
        }
        printf("%d",ptr->data);
    }
}

struct node* insertAtBegin(struct node *head,int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    if(head == NULL)    newNode->next = NULL;
    else                newNode->next = head;
    return newNode;
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int val;
        scanf("%d",&val);
        head = insertAtBegin(head, val);
    }
    print(head);
    return 0;
}
