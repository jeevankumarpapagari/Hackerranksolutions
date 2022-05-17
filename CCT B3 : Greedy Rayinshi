#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    int cards[n], i, j, k = 1;
    for(i=0;i<n;i++)
        scanf("%d",&cards[i]);
    
    i = 0;
    j = n-1;
    long riyanshi = 0, neechea = 0;
    while(i <= j)
    {
        if(k++%2)
            riyanshi += cards[i] >= cards[j] ? cards[i++] : cards[j--];
        else
            neechea += cards[i] >= cards[j] ? cards[i++] : cards[j--];
    }
    printf("%ld %ld",riyanshi,neechea);
    return 0;
}
