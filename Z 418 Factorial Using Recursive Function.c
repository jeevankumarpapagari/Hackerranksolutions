#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long long fact(int n)
{
    if(n<=0)    return 1;
    return n * fact(n-1);
}

int main() 
{
    int n;
    scanf("%d",&n);
    printf("%lld",fact(n));
    return 0;
}
