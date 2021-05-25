#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void print(int n)
{
    if(n)
    {
        print(n-1);
        printf("%d ",n);
    }
}

int main() 
{
    int n;
    scanf("%d",&n);
    print(n);
    return 0;
}
