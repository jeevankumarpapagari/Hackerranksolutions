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
        printf("\n");
    }
}

struct node* insertAtEnd(struct node *head, int data)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL)    return newNode;
    else
    {
        struct node *ptr = head;
        while(ptr->next!=NULL)
            ptr = ptr->next;
        ptr->next = newNode;
        return head;
    }
}

struct node* deleteAtEnd(struct node *head)
{
    if(head==NULL || head->next == NULL)    return NULL;
    else
    {
        struct node *ptr = head, *temp;
        while(ptr->next!=NULL)
        {
            temp = ptr;
            ptr = ptr->next;
        }
        temp->next = NULL;
        free(ptr);
        return head;
    }
}

int main()
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int val;
        scanf("%d",&val);
        head = insertAtEnd(head,val);
    }
    int delCount;
    scanf("%d",&delCount);
    int i;
    for(i=1;i<=delCount;i++)
        head = deleteAtEnd(head);
    print(head);
    return 0;
}
