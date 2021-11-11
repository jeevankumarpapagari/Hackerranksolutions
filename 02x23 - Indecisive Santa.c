#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int a[201][201],n,m,g11,g12,g21,g22;
int min1,min2;
int main() 
{
    scanf("%d%d%d%d%d%d",&n,&m,&g11,&g12,&g21,&g22);
    int k=0,x,y;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
           if(i<g11)    x=g11-i;
           
           else         x=i-g11;
          
           if(j<g12)    y=g12-j;

           else y=j-g12;
           
           min1=x+y;
           
           if(i<g21)    x=g21-i;
           
           else         x=i-g21;
          
           if(j<g22)    y=g22-j;

           else y=j-g22;
           min2=x+y;
           if(min1==min2)k++;
        }
    }
    printf("%d",k);
    return 0;
}
