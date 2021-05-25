#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int numberOfRows;
    scanf("%d",&numberOfRows);
    
    int i, j; 
    long long c = 1;
    
    for(i=0;i<numberOfRows;i++)
    {
        for(j=0;j<=i;j++)
        {
            if(j==0)    c = 1;
            else        c = c * (i-j+1)/j;
            printf("%lld ",c);                
        }
        printf("\n");
    }
    return 0;
}
