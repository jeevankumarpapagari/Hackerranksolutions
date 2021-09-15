#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long min(long x,long y)
{
    return x < y ? x : y;
}

long minimum(long a,long b,long c)
{
    return min(min(a,b),c);
}

int main() 
{
    long n;
    scanf("%ld",&n);
    
    long a[n+1], i;
    for(i=1;i<=n;i++)
        scanf("%ld",&a[i]);
    
    long m;
    scanf("%ld",&m);
    
    long b[m+1], j;
    for(j=1;j<=m;j++)
        scanf("%ld",&b[j]);
    
    long x,y,z;
    scanf("%ld %ld %ld",&x,&y,&z);
    
    long grid[n+1][m+1];
    
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i == 0)              grid[i][j] = j*x;
            else if(j == 0)         grid[i][j] = i*y;
            else if(a[i] == b[j])   grid[i][j] = grid[i-1][j-1];
            else                    grid[i][j] = minimum(x+grid[i][j-1], y+grid[i-1][j], z+grid[i-1][j-1]);
        }
    }
    
    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
            printf("%d\t",grid[i][j]);
        printf("\n");
    }*/
    printf("%ld",grid[n][m]);
    return 0;
}
