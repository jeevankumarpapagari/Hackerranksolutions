#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int min(int x,int y)
{
    return x<y ? x : y;
}

int main() 
{
    int r,c;
    scanf("%d %d",&r,&c);
    
    int arr[r][c], i, j;
    for(i=0;i<r;i++)
        for(j=0;j<c;j++)
            scanf("%d",&arr[i][j]);
    
    int result[r][c], sum = 0;
    
    for(i=0;i<c;i++)
    {
        result[0][i] = sum + arr[0][i];
        sum = result[0][i];
    }
    
    sum = 0;
    for(i=0;i<r;i++)
    {
        result[i][0] = sum + arr[i][0];
        sum = result[i][0];
    }
    
    for(i=1;i<r;i++)
        for(j=1;j<c;j++)
            result[i][j] = min(result[i][j-1],result[i-1][j]) + arr[i][j];
    
    /*for(i=0;i<r;i++)
    {
        for(j=0;j<c;j++)
            printf("%d ",result[i][j]);
        printf("\n");
    }*/
    
    printf("%d",result[r-1][c-1]);
    return 0;
}
