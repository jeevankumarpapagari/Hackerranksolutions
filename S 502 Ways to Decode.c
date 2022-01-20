#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long m = 1e9+7;
long findWays(char *s)
{
    int *count, i, n;
    
    if(!s || s[0]=='0')
        return 0;
    
    n = strlen(s);
    if(n==1)
        return 1;
    
    count = (int*) malloc(sizeof(int)*(n+1));
    count[0] = count[1] = 1;
    
    for(i=2;i<=n;i++)
    {
        count[i] = 0;
        if(s[i-1] >= '0')
            count[i] = count[i-1];
        if(s[i-2]=='0' || s[i-2]=='1' || (s[i-2]=='2' && s[i-1]<'6'))
            count[i] = (count[i] + count[i-2])%m;; 
    }
    return count[n];  
} 

int main() 
{
    char str[1000000];
    scanf("%s",str);
    
    printf("%ld",findWays(str));
    
    
    return 0;
}
