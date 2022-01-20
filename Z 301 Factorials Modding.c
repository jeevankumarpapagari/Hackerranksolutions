#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
long long int anw=1;
void func(long long int a,long long int b, long long int m)
{
    for(int i=a;i>b;i--)
    {
        anw*=i;
        anw%=m;
    }
}
 
int main() 
{
    long long int a,b,m;
    scanf("%lld%lld%lld",&a,&b,&m);
    func(a,b,m);
    anw%=m;
    printf("%lld",anw);
    return 0;
}
