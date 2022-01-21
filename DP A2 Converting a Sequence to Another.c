#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int min(int x,int y)
{
    return x<=y ? x : y;
}

int main() 
{
    int n;
    scanf("%d",&n);
    
    int A[n+1], i;
    for(i=1;i<=n;i++)
        scanf("%d",&A[i]);
    
    int m;
    scanf("%d",&m);
    
    int B[m+1], j;
    for(j=1;j<=m;j++)
        scanf("%d",&B[j]);
    
    int grid[n+1][m+1];
    
    for(i=0;i<=n;i++)
        for(j=0;j<=m;j++)
            grid[i][j] = i==0 ? j : j==0 ? i : A[i]==B[j] ? grid[i-1][j-1] : min(min(grid[i][j-1],grid[i-1][j]),grid[i-1][j-1])+1;
    
    printf("%d",grid[n][m]);
    return 0;
}
