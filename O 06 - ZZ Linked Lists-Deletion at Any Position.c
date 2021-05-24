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

struct node* deleteAtBegin(struct node *head)
{
    if(head == NULL || head->next == NULL)  return NULL;
    else    //return head->next;
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}

struct node* deleteAtPos(struct node *head, int pos)
{
    if(pos == 0)    return deleteAtBegin(head);
    else
    {
        struct node *ptr = head, *temp;
        int i;
        for(i=1;i<=pos-1;i++)   ptr = ptr->next;
        temp = ptr->next;
        ptr->next = temp->next;//ptr->next = ptr->next->next;
        free(temp);
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
    int pos;
    scanf("%d",&pos);
    head = deleteAtPos(head,pos);
    print(head);
    return 0;
}
