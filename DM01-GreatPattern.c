#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int testCases;
    scanf("%d",&testCases);
    while(testCases--)
    {
        int n;    
        scanf("%d",&n);
        int i,j;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n-i;j++)     printf("  ");
            for(j=1;j<=i;j++)       printf("%d ",j);
            for(j=i-1;j>=1;j--)     printf("%d ",j);
            printf("\n");
        }
        for(i=1;i<n;i++)
        {
            for(j=1;j<=i;j++)       printf("  ");
            for(j=1;j<=n-i;j++)     printf("%d ",j);
            for(j=n-i-1;j>=1;j--)     printf("%d ",j);
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
