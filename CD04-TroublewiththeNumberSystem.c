#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n,i;
    long long int result = 1, num, countOfZeros=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&num);
        while(num%10 == 0)
        {
            countOfZeros++;
            num = num/10;
        }
        result = result * num;
    }
    printf("%lld",result);
    for(i=1;i<=countOfZeros;i++)
        printf("%d",0);
    return 0;
}
