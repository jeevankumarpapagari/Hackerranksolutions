#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
/*
    log(a*b) = log(a) * log(b)
    log(n!) = log(1 * 2 * 3 ...... * n) 
*/
short numberOfDigits(short n)
{
    if(n<0)     return 0;
    if(n<=1)    return 1;
    double digits = 0;
    int i;
    for(i=2;i<=n;i++)
        digits += log10(i);
    return (short)(ceil(digits));
}
int main() 
{
    short n;
    scanf("%hd",&n);
    printf("%d",numberOfDigits(n));
    return 0;
}
