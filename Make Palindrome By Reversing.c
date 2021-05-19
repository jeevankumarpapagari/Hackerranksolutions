#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int reverseNumber(int n)
{
    int rev = 0;
    while(n)
    {
        rev = rev * 10 + n%10;
        n = n/10;
    }
    return rev;
}
int main() 
{
    int n,counter = 5;
    scanf("%d",&n);
    while(counter--)
    {
        n = n + reverseNumber(n);
        if(n == reverseNumber(n))
        {
            printf("%d\nYES",n);
            return 0;
        }
    }
    printf("NO");
    return 0;
}
