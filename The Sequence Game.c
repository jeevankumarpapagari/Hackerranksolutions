#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long max(long x,long y)
{
    return x>=y?x:y;
}
int main() 
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n; scanf("%d",&n);
        long c[100005]={0},dp[100005]={0};
        for(int i=0;i<n;i++)
        {
            int x;scanf("%d",&x);
            c[x]++;
        }
        dp[0]=0;dp[1]=c[1];
        for(int i=2;i<=100000;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+(1L*i*c[i]));
        }
        printf("%ld\n",dp[100000]);
    }
    
    return 0;
}
