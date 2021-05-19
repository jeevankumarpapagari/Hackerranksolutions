#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{   
    int n;
    scanf("%d",&n);
    int giftOrder[n],i,j;
    for(i=0;i<n;i++)
        scanf("%d",&giftOrder[i]);
    //Process the operation
    for(i=1;i<=n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i == giftOrder[j])
            {
                printf("%d ",j+1);
                break;
            }
        }
    }
    return 0;
}