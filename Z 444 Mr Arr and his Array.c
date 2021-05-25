#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n,rotation;
    scanf("%d%d",&n,&rotation);
    int arr[n],i;
    for(i=0;i<n;i++)    scanf("%d",&arr[i]);
    for(i=rotation;i<n;i++) printf("%d ",arr[i]);
    for(i=0;i<rotation;i++) printf("%d ",arr[i]);
    return 0;
}
