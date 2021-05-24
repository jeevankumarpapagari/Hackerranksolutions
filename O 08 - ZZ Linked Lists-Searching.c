#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

struct node *head = NULL;

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

void searchElement(struct node *head,int key)
{
    struct node *ptr = head;
    while(ptr)
    {
        if(key == ptr->data)
        {
            printf("yes");
            return;
        }
        ptr = ptr->next;
    }
    printf("no");
    return;
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
    int keyValue;
    scanf("%d",&keyValue);
    searchElement(head,keyValue);
    return 0;
}
