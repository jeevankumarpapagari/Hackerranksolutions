#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long stack[1000000], top = -1;

void push(long id)
{
    top++;
    stack[top] = id;
}

void exchangeTopWithBelow()
{
    long temp = stack[top];
    stack[top] = stack[top-1];
    stack[top-1] = temp;
}

int main() 
{
    int tc;
    scanf("%d",&tc);
    while(tc--)
    {
        long n,id,i;
        scanf("%ld %ld",&n,&id);
        push(id);
        for(i=1;i<=n;i++)
        {
            char pass[5];
            scanf("%s",pass);
            if(pass[0] == 'P')
            {
                long id;
                scanf("%ld",&id);
                push(id);
            }
            else
            {
                exchangeTopWithBelow();
            }
        }
        printf("Player %ld\n",stack[top]);
    }
    return 0;
}
