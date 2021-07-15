#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter value of n: ");
    scanf("%d",&n);

    int arr[n], i, j, operationsCount = 0, swapCount = 0;
    for(i=0;i<n;i++)
        arr[i] = n-i;//rand() % 49;
    
    printf("\nElements of the list before sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    for(i=0;i<n-1;i++)
    {
        int minValueIndex = i;
        for(j=i+1;j<n;j++)
        {
            operationsCount++;
            if(arr[j] < arr[minValueIndex])
                minValueIndex = j;
        }
        if(minValueIndex != i)
        {
            swapCount++;
            int temp = arr[i];
            arr[i] = arr[minValueIndex];
            arr[minValueIndex] = temp; 
        }
    }

    printf("\nElements of the list after sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nTotal Operations: %d\nTotal Swapcount: %d",operationsCount,swapCount);
}