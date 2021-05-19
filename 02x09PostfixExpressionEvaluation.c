#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

int stack[100], top=-1;

void push(int n)
{
    stack[++top] = n;
}

int pop()
{
    return stack[top--];
}
int main() 
{
    char str[100];
    scanf("%s",str);
    int i=-1,x,y,z;
    while(str[++i])
    {
        if(isupper(str[i]))
        {
            int num;
            scanf("%d",&num);
            push(num);
        }
        else
        {
            x = pop();
            y = pop();
            switch(str[i])
            {
                case '+': z = y+x; break;
                case '-': z = y-x; break;
                case '*': z = y*x; break;
                case '/': z = y/x; break;
            }
            push(z);
        }
    }
    printf("%d",pop());
    return 0;
}
