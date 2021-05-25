#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int testCases;
    scanf("%d",&testCases);
    if (testCases >=1 && testCases <= 1000)
    {
        while(testCases--)
        {
            long int type1IdliCost, type2IdliCost, totalAmout;
            scanf("%ld%ld%ld",&type1IdliCost,&type2IdliCost,&totalAmout);
            (type1IdliCost <= type2IdliCost) ? printf("%ld\n",totalAmout/type1IdliCost) : printf("%ld\n",totalAmout/type2IdliCost);
        }
    }
    return 0;
}
