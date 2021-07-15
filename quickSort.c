#include<stdio.h>
#include<stdlib.h>

void swap(int *x,int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int arr[],int l,int r)
{
    int pivotValue = arr[r];
    int i = l-1, j;
    for(j=l;j<r;j++)
    {
        if(arr[j] <= pivotValue)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[r]);
    return i+1;
}

void quickSort(int arr[],int l, int r)
{
    if(l < r)
    {
        int pivotIndex = partition(arr,l,r);
        quickSort(arr,l,pivotIndex-1);
        quickSort(arr,pivotIndex+1,r);
    }
}

int main()
{
    int n;
    printf("Enter value of n: ");
    scanf("%d",&n);

    int arr[n], i;
    for(i=0;i<n;i++)
        arr[i] = rand() % 49;
    
    printf("\nElements of the list before sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    quickSort(arr,0,n-1);

    printf("\nElements of the list after sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}