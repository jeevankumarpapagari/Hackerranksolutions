#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void displayBinaryValue(long long int n)
{
    if(n)
    {
        displayBinaryValue(n/2);
        printf("%lld",n%2);
    }
}

int main() 
{
    long long int n;
    scanf("%lld",&n);
    if(n==0)    printf("0");
    else        displayBinaryValue(n);
    return 0;
}
