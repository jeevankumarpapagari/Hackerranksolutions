#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define MAX 1000000
int stack[MAX],top=-1;
void push()
{
    if(top==MAX-1)  return;//Overflow Condition
    int newElement;
    scanf("%d",&newElement);
    stack[++top] = newElement;    
}
void pop()
{
    if(top==-1)
    {
        printf("Invalid\n");
        return;
    }
    top--;
}
void callMin()
{
    if(top==-1)//Underflow condition
    {
        printf("Invalid\n");
        return;
    }
    int min = stack[top], i;
    for(i=top;i>=0;i--)
        if(min > stack[i])
            min = stack[i];
    printf("%d\n",min);
}
void callMax()
{
    if(top==-1)
    {
        printf("Invalid\n");
        return;
    }
    int max = stack[top],i;
    for(i=top;i>=0;i--)
        if(max < stack[i])
            max = stack[i];
    printf("%d\n",max);
}
int main() 
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        char operation[10];
        scanf("%s",operation);
        if(strcmp(operation,"Add")==0)          push();
        if(strcmp(operation,"CallMin")==0)      callMin();
        if(strcmp(operation,"CallMax")==0)      callMax();
        if(strcmp(operation,"Remove")==0)       pop();
    }
    return 0;
}
