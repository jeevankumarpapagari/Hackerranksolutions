#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *a,const void *b)
{
    return *(int*)a - *(int*)b;
}

int binarySearch(int arr[],int n,int k)
{
    int left = 0, right = n-1;
    while(left <= right)
    {
        int middle = (left+right)/2;
        if(arr[middle] == k)        return 1;
        else if(arr[middle] < k)    left = middle + 1;
        else                        right = middle - 1;
    }
    return 0;
}

int main() 
{
    int n;
    scanf("%d",&n);
    int arr[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    qsort(arr,n,sizeof(int),compare);
    int twoSum,result=0;
    scanf("%d",&twoSum);
    for(i=0;i<n;i++)
    {
        if(binarySearch(arr, n, twoSum-arr[i]) == 1)
           result++;
    }
    printf("%d",result);
    return 0;
}
