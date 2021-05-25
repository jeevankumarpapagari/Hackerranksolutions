#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    6n + 1 : 
    6n - 1 : 
    2 3 
    5: 6*1-1 
    7: 6*1+1 
    11: 6*2-1 
    13: 6*2+1 
    17: 6*3-1 
    19: 6*3+1 
    23: 6*4-1
    29: 6*5-1 
    31: 6*5+1 
    37: 6*6+1 
    41: 6*7-1 
    43: 6*7+1 
    47: 6*8-1 
    49: 6*8+1
    
*/

int isPrime(unsigned long long n)
{
    if(n==2 || n==3)                    return 1;
    else if(n==1 || n%2==0 || n%3==0)   return 0;
    else
    {
        unsigned long long i;
        for(i=5;i<=sqrt(n);i+=6)
            if(n%i==0 || n%(i+2)==0)
                return 0;
    }
    return 1;
}

int main() 
{
    unsigned long long beginningNumber, endingNumber, i, count = 0;
    scanf("%llu%llu",&beginningNumber,&endingNumber);
    for(i=beginningNumber;i<=endingNumber;i++)
        if(isPrime(i))
            count++;
    printf("%llu",count);
    return 0;
}
