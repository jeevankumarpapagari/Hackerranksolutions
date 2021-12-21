#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int result = 0;
    for(int i=0; i<=1;i++)
        for(int j=0;j<=1;j++)
            for(int k=0;k<=1;k++)
                if(i+j+k >= 2)
                    result++;
    printf("%d",result);
    return 0;
}
