#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    int arr[n][n], brr[n][n];
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&arr[i][j]);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            brr[i][j] = arr[i][j] || arr[j][n-i-1] || arr[n-i-1][n-j-1] || arr[n-j-1][i];
            printf("%d ",brr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
