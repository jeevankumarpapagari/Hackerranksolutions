#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long stack[10000000],top=-1;

void push(long n)
{
    stack[++top] = n;
}

void pop()
{
    top--;
}

long maxOfStack()
{
    long maxValue = stack[top],i;
    for(i=top;i>=0;i--)
        if(maxValue < stack[i])
            maxValue = stack[i];
    return maxValue;
}

int main() 
{
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int choice;
        scanf("%d",&choice);
        if(choice == 1)
        {
            long newValue;
            scanf("%ld",&newValue);
            push(newValue);
        }
        if(choice == 2)     pop();
        if(choice == 3)     printf("%ld\n",maxOfStack());
            
    }
    return 0;
}
