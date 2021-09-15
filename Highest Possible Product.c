#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *x,const void *y)
{
    return *(int*)y - *(int*)x;
}

int main() 
{
    int n;
    scanf("%d",&n);
    
    int arr[n], i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    qsort(arr,n,sizeof(int),compare);
    
    long product1 = arr[0]*arr[1]*arr[2];
    long product2 = arr[n-1]*arr[n-2]*arr[0];
    
    product1 >= product2 ? printf("%ld",product1) : printf("%ld",product2);
    
    return 0;
}
