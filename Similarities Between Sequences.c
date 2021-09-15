#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    int a[n+1],i;
    for(i=1;i<=n;i++)
        scanf("%d",&a[i]);
    
    int m;
    scanf("%d",&m);
    
    int b[m+1],j;
    for(j=1;j<=m;j++)
        scanf("%d",&b[j]);
    
    int grid[n+1][m+1], max = 0;
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0 || j==0)            grid[i][j] = 0;
            else if(a[i] == b[j])       grid[i][j] = grid[i-1][j-1] + 1;
            else                        grid[i][j] = 0;
            
            if(max < grid[i][j])
                max = grid[i][j];
        }
    }
    printf("%d",max);
    
    return 0;
}
