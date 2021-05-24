#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int m[1000000][2] = {0};
int st1[1000000], st2[1000000];
int top1 = -1,top2 = -1, x;

int pop1()
{
    return st1[top1--];
}

int pop2()
{
    return st2[top2--];
}

int main() 
{
    int n,i;
    scanf("%d",&n);
    
    int head, child;
    char pos;
    
    for(i=0;i<n-1;i++)
    {
        scanf("%d%d %c",&head,&child,&pos);
        if(pos == 'L')      m[head][0] = child;
        else                m[head][1] = child;
    }
    
    st1[++top1] = 1;
    while(top1!=-1 || top2!=-1)
    {
        while(top1 >= 0)
        {
            x = pop1();
            if(x!=0)
            {
                printf("%d ",x);
                st2[++top2] = m[x][0];
                st2[++top2] = m[x][1];
            }
        }
        while(top2 >= 0)
        {
            x = pop2();
            if(x!=0)
            {
                printf("%d ",x);
                st1[++top1] = m[x][1];
                st1[++top1] = m[x][0];
            }
        }
    }
    
    return 0;
}
