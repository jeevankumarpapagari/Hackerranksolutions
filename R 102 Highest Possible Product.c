#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *x, const void *y)
{
    return *(int*)y - *(int*)x;
}

int main() 
{
    int n;
    scanf("%d",&n); //Reading total number of elements value into the program
    
    int arr[n], i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]); //Reading list of elements into an array
    
    qsort(arr,n,sizeof(int),compare); //Sorting list of data in descending order
    
    long long max1 = arr[0] * arr[1] * arr[2];
    long long max2 = arr[n-1] * arr[n-2] * arr[0];
    
    max1 > max2 ? printf("%lld",max1) : printf("%lld",max2);
    
    return 0;
}
