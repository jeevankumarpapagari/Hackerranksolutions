#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max(int a,int b)
{
    if(a<=b)return b;
    else return a;
}
int knap(int n,int *w,int *p,int m)
{
    int k[n+1][m+1],i,j;
   for (i = 0; i <= n; i++)
   {
       for (j = 0; j<= m; j++)
       {
           if (i==0 || j==0)
               k[i][j] = 0;
           else if (w[i-1] <= j)
                 k[i][j] = max(p[i-1] + k[i-1][j-w[i-1]],  k[i-1][j]);
           else
                 k[i][j] = k[i-1][j];
       }
   }
 
   return k[n][m];
}
int main() {
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d%d",&n,&m);
        int w[n],p[n];
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&w[i],&p[i]);
        }
        int x=knap(n,w,p,m);
        printf("%d\n",x);
    }
    return 0;
}
