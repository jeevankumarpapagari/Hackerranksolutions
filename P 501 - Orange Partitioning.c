#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void swap(int *x,int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void makePartition(int arr[],int left,int right)
{
    int pivotNumber = arr[right];
    int i = left - 1, j;
    
    for(j=left;j<right;j++)
    {
        if(arr[j] <= pivotNumber)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[right]);
}


int main() 
{
    int n;
    scanf("%d",&n);
    
    int arr[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    makePartition(arr,0,n-1);
    
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
