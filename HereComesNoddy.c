#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int row,col;
    scanf("%d%d",&row,&col);
    int arr[row][col], i, j;
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%d",&arr[i][j]);
    
    int rowIndex = 0;
    int colIndex = 0;
    
    while(rowIndex<row && colIndex<col)
    {
        for(i=colIndex; i<col;i++)      printf("%d ",arr[rowIndex][i]);
        rowIndex++; 
        for(i=rowIndex; i<row; i++)     printf("%d ",arr[i][col-1]);  
        col--;
        if(rowIndex < row)
        {
            for(i=col-1;i>=colIndex;i--)  printf("%d ",arr[row-1][i]);
            row--;
        }
        if(colIndex < col)
        {
            for(i=row-1; i>=rowIndex; i--)   printf("%d ",arr[i][colIndex]);
            colIndex++;
        }
    }
    return 0;
}
