#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    short n;
    scanf("%hd",&n);
    
    short arr[n],i;
    for(i=0;i<n;i++)    
    {
        scanf("%hd",&arr[i]);
        arr[i] = (i%2==0) ? arr[i]*2 : arr[i]/2;
        /*if(i%2==0)  arr[i] *= 2;
        else        arr[i] /= 2;*/
    }

    for(i=0;i<n;i++)    printf("%hd ",arr[i]);
    return 0;
}
