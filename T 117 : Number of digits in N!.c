#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    if(n<0)
        printf("0");
    else if(n<=1)
        printf("1");
    else
    {
        double digits = 0;
        for(int i=2;i<=n;i++)
            digits += log10(i);
        int result = ceil(digits);
        printf("%d",result);
    }
    return 0;
}
