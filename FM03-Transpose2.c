#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int row,col,i,j;
    scanf("%d%d",&row,&col);
    
    int matrix[row][col];
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            scanf("%d ",&matrix[i][j]);
    /*
        1 2 3 4     00  01  02  03
        5 6 7 8     10  11  12  13
        
        1 5     00 10
        2 6     01 11
        3 7     02 12
        4 8     03 13
    */
    for(i=0;i<col;i++)
    {
        for(j=0;j<row;j++)
            printf("%d ",matrix[j][i]);
        printf("\n");
    }
    
    return 0;
}
