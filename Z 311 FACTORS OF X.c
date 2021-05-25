#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int testCases;
    scanf("%d",&testCases);
    while(testCases--)
    {
        int var,i;
        scanf("%d",&var);
        for(i=1;i<=var;i++)
            if(var % i == 0)
                printf("%d ",i);
        printf("\n");
    }
    return 0;
}
