#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter value of n: ");
    scanf("%d",&n);

    int arr[n], i, j, operationsCount = 0;
    for(i=0;i<n;i++)
        arr[i] = n-i;//rand() % 49;
    
    printf("\nElements of the list before sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    for(i=1;i<n;i++)
    {
        int key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key)
        {
            operationsCount++;
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }

    printf("\nElements of the list after sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nTotal Operations: %d",operationsCount);
}