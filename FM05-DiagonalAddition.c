#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    int matrix[n][n],i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&matrix[i][j]);
    
    int sum = 0;
    for(i=0;i<n;i++)
        sum = sum + matrix[i][i] + matrix[i][n-1-i];
    
    if(n%2)     sum = sum - matrix[n/2][n/2];
    
    printf("%d",sum);
    return 0;
}
