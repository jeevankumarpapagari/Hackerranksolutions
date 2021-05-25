#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    short n;
    scanf("%hd",&n);
    int matrix[n][n], i, j, left, top, x;
    
    left = 0;
    top = n-1;
    x = 1;
    
    for(i=1;i<=n/2;i++,left++,top--)
    {
        for(j=left;j<=top;j++)      matrix[left][j] = x++; //Filling from left to right
        for(j=left+1;j<=top;j++)    matrix[j][top] = x++; //Filling from top to botton [right row]
        for(j=top-1;j>=left;j--)    matrix[top][j] = x++; //Filling from right to left bottom row
        for(j=top-1;j>=left+1;j--)    matrix[j][left] = x++; //Filling from bottom to top [left row]
    }
    if(n%2)     matrix[n/2][n/2] = x;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",matrix[i][j]);
        printf("\n");
    }
    return 0;
}
