#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int isPrime(int n)
{
    int i;
    for(i=2;i<=n/2;i++)
        if(n%i==0)
            return 0;
    return 1;
}
int main() 
{   
    int n,i;
    scanf("%d",&n);
    int primes[10000],j=0,k;
    for(i=2;i<n;i++)
    {
        if(isPrime(i))
            primes[j++] = i;
    }
    /*printf("Prime Count: %d\n",j);
    for(i=0;i<j;i++)
        printf("%d ",primes[i]);*/
    for(i=0;i<j-1;i++)
    {
        for(k=i+1;k<j;k++)
        {
            if(primes[i] + primes[k] == n)
            {
                printf("YES");
                return 0;
            }
        }
    }
    printf("NO");
    return 0;
}
