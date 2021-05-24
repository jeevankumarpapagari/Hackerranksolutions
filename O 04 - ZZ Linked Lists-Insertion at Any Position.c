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

struct node* insertAtPosition(struct node *head,int data,int pos)
{
    if(pos == 0)    return  insertAtBegin(head,data);
    else
    {
        struct node *newNode = (struct node*)malloc(sizeof(struct node)), *ptr = head;
        newNode->data = data;
        int i;
        for(i=1;i<=pos-1;i++)
            ptr = ptr->next;
        
        newNode->next = ptr->next;
        ptr->next = newNode;
        return head;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int pos,val;
        scanf("%d%d",&pos,&val);
        head = insertAtPosition(head, val, pos);
    }
    print(head);
    return 0;
}
