#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPrime(int n)
{
    if(n==2 || n==3)
        return true;
    if(n%2 == 0 || n%3==0)
        return false;
    for(int i=5;i<=sqrt(n);i+=6)
        if(n%i==0 || n%(i+2)==0)
            return false;
    return true;
}

int main() 
{
    long n;
    scanf("%ld",&n);
    
    int a[100000], i=1, j;  
    a[0]=2;

    for(j=3;i<100000;j+=2)
        if(isPrime(j)) 
            a[i++]=j;
    
    i=1;
    long sum=2, c=0;
    while(sum<n) 
    {
        sum += a[i];
        if(sum<=n && isPrime(sum))     
            c++;
        i++; 
    }
    printf("%ld",c);

    return 0;
}
