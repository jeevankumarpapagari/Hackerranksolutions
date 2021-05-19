#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    int arr[n],i;
    for(i=0;i<n;i++)    scanf("%d",&arr[i]);
    int rotation;
    scanf("%d",&rotation);
    rotation = rotation%n;
    for(i=0;i<n;i++)
    {
        if(i<rotation)      printf("%d ",arr[n+i-rotation]);
        else                printf("%d ",arr[i-rotation]);
    }
    return 0;
}
