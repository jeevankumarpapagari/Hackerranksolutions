#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int number;
    scanf("%d",&number);
    if(number>=1 && number<=pow(10,5))
    {
        int count = 0, i;
        //Prepare a loop which genertes numbers from 1 to number
        for(i=1;i<=number;i++)
        {
            if(number % i == 0)
                count++;
        }
        if(count == 2)      printf("yes");
        else                printf("no");
    }
    return 0;
}