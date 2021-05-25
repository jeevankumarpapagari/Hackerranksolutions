#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    int arr[n][n],i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    int rm = 0, cm = 0;
    //row-major value
    for(i=0;i<n;i++)
    {
        for(j=1;j<n;j++)
            rm = rm + (arr[i][j-1] * arr[i][j]);
        if(i != n-1)
            rm = rm + (arr[i][j-1] * arr[i+1][0]);
    }
    //column-major value
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(i!=0 && j==0)
                cm = cm + (arr[n-1][i-1] * arr[j][i]);
            cm = cm + (arr[j][i] * arr[j+1][i]);
        }
    }
    rm <= cm ? printf("row-major") : printf("column-major");
    return 0;
}
