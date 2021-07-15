#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int l,int m,int r)
{
    int n1 = m-l+1;
    int n2 = r-m;

    int LeftArr[n1], rightArr[n2];

    int i = 0;
    for(i=0;i<n1;i++)   LeftArr[i] = arr[l+i];
    for(i=0;i<n2;i++)   rightArr[i] = arr[m+1+i];

    int j = 0, k = l;
    i = 0;
    while(i<n1 && j<n2)
    {
        if(LeftArr[i] <= rightArr[j])   arr[k++] = LeftArr[i++];
        else                            arr[k++] = rightArr[j++];
    }
    while(i<n1)     arr[k++] = LeftArr[i++];
    while(j<n2)     arr[k++] = rightArr[j++];
}

void mergeSort(int arr[],int l,int r)
{
    if(l < r)
    {
        int m = (l+r)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
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

    mergeSort(arr,0,n-1);

    printf("\nElements of the list after sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
}