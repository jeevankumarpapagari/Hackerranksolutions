#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int isPrime(int n)
{
    for(int i=2;i<=sqrt(n);i++)
        if(n%i==0)
            return 0;
    return 1;
}

int main() 
{
    long n;
    scanf("%ld",&n);
    
    int primes[100000];
    primes[0] = 2;
    int i,j=1;
    
    for(i=3;j<=100000;i+=2)
        if(isPrime(i))
            primes[j++] = i;
    
    i = 1;
    long sum = 2, result = 0;
    
    while(sum < n)
    {
        sum = sum + primes[i++];
        if(sum <=n && isPrime(sum))
            result++;
    }
    
    printf("%ld",result);
    return 0;
}
