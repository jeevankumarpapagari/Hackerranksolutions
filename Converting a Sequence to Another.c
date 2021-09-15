#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    int a[n], i;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    int m;
    scanf("%d",&m);
    
    int b[m], j;
    for(j=1;j<=m;j++)
        scanf("%d",&b[j]);
    
    int grid[n+1][m+1];
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0)            grid[i][j] = j;
            else if(j==0)       grid[i][j] = i;
            else if(a[i]==b[j]) grid[i][j] = grid[i-1][j-1];
            else                grid[i][j] = (grid[i][j-1]<=grid[i-1][j-1] && grid[i][j-1]<=grid[i-1][j]) ? grid[i][j-1]+1 : (grid[i-1][j]<=grid[i-1][j-1] && grid[i-1][j]<=grid[i][j-1]) ? grid[i-1][j]+1 : grid[i-1][j-1]+1;
        }
    }
    
    printf("%d",grid[n][m]);
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
            printf("%d\t",grid[i][j]);
        printf("\n");
    }*/
    return 0;
}
