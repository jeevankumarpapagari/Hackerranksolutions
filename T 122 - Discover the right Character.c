#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n,index=0,j=0;
    scanf("%d",&n);
    char str[32];
    while(n)
    {
        index = (n-1)%26;
        str[j++] = (index+'A');
        n = (n-1)/26;
    }
    for(index=--j;index>=0;index--)
        printf("%c",str[index]);
    return 0;
}
