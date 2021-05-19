#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
    18: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 => 1 2 3 6 9 18 => 18/2 = 9
    10: 1 2 3 4 5 6 7 8 9 10 => 1 2 5 10 => 10/2 => 5
    24: 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 => 1 2 3 4 6 8 12 24 => 24/2 = 12
    
    36 => sqrt(36) => 6 [2 3 4 5 6]
    17 => sqrt(17) => 5 [2,3,4,5]
*/


int main() 
{
    int numberOfQueries;
    scanf("%d",&numberOfQueries);
    while(numberOfQueries--)
    {
        int number,i;
        short factorsCount = 0;
        scanf("%d",&number);
        if(number==1)    printf("no\n");
        else
        {
            for(i=2;i<=sqrt(number);i++)
            {
                if(number%i == 0)
                {
                    factorsCount++;
                    break;
                }
            }
            if(factorsCount == 0)   printf("yes\n");
            else                    printf("no\n");
        }
    }
    return 0;
}