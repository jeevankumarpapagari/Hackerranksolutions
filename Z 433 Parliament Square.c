#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    long long int n,m,a,r,w;
    scanf("%lld%lld%lld",&n,&m,&a);
    if(m%a==0)  r = m/a;
    else        r = m/a+1;
    if(n%a==0)  w = n/a;
    else        w = n/a+1;
    
    printf("%lld",r*w);
    return 0;
}
