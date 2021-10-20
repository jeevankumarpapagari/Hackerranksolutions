#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *x,const void *y)
{
    return *(int*)x - *(int*)y;
}

int main() 
{
    int n, gc;
    scanf("%d %d",&n,&gc);
    
    int coin[n], i;
    for(i=0;i<n;i++)
        scanf("%d",&coin[i]);
    
    qsort(coin,n,sizeof(int),compare);
    
    int j = 0, flag = 0;
    
    for(i=0;i<gc;i++)
    {
        int giftValue, sum = 0, coinCount = 0;
        scanf("%d",&giftValue);
        while(sum < giftValue)
        {
            if(j == n)
            {
                flag = 1;
                break;
            }
            sum += coin[j++];
            coinCount++;
        }
        flag ? printf("-1 -1\n") : printf("%d %d\n",coinCount,sum);
    }
    return 0;
}
