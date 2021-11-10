#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int a[11][11],n;
int safe(int n,int c,int r)
{
    for(int i=0;i<r;i++)
        if(a[i][c])return 0;
    for(int i=r,j=c;i>=0 && j>=0;i--,j--)
        if(a[i][j])return 0;
    for(int i=r,j=c;i>=0 && j<n;i--,j++)
        if(a[i][j])return 0;
    return 1;
}
int solvequeen(int n,int r)
{
    if(r==n)return 1;
    for(int i=0;i<n;i++)
    {
        if(safe(n,i,r))
        {
            a[r][i]=1;
            if(solvequeen(n,r+1))return 1;
            a[r][i]=0;
        }
    }
    return 0;
}
int main() {
    scanf("%d",&n);
    if(solvequeen(n,0))
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",a[i][j]);
            }
            printf("\n");
        }
    }
    else printf("Not Possible");
    return 0;
}
