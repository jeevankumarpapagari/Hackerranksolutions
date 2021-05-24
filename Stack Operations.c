#include<stdio.h>
#define MAX 20

int stack[MAX], top = -1;

void push()
{
    if(top == MAX-1)
    {
        printf("\nStack is overflow\n");
        return;
    }
    int newValue;
    printf("\nEnter a new value:");
    scanf("%d",&newValue);
    stack[++top] = newValue;
}

void pop()
{
    if(top == -1)
    {
        printf("\nStack is underflow\n");
        return;
    }
    top--;
}

void display()
{
    if(top == -1)
    {
        printf("\nStack is empty, not contain any elements\n");
        return;
    }
    int i;
    for(i=top;i>=0;i--)
        printf("\nLocation: %d\tValue: %d",i,stack[i]);
    printf("\n");
}

int main()
{
    int choice;
    do
    {
        printf("\nEnter your choice:\n1. Push operation\n2. Pop operation\n3. Display\n0.Exit\nAnswer:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break; 
        }
    }while(choice!=0);   
}
