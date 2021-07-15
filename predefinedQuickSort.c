#include<stdio.h>
#include<stdlib.h>

int compare(const void *x,const void *y)
{
    return *(int*)x - *(int*)y;
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

    qsort(arr,n,sizeof(int),compare);

    printf("\nElements of the list after sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}