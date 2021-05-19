#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int weight;
    scanf("%d",&weight);
    if(weight >= 1 && weight <= 100)
    {
        if(weight % 2 == 1 || weight == 2)          printf("NO");
        else                                        printf("YES");
    }
    return 0;
}
