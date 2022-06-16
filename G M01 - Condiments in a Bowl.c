#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int tc,gc;
    scanf("%d %d",&tc,&gc);
    
    int guest[gc], i;
    for(i=0;i<gc;i++)
        scanf("%d",&guest[i]);
    
    long result = 0, temp = tc;
    for(i=0;i<gc-1;i++)
    {
        temp = temp - guest[i];
        if(temp < 5)
        {
            result = result + (tc-temp);
            temp = tc;
        }
    }
    printf("%ld",result);
    return 0;
}
