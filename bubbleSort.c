#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter value of n: ");
    scanf("%d",&n);

    int arr[n], i, j, operationsCount = 0, swapCount = 0;
    for(i=0;i<n;i++)
        arr[i] = rand() % 49;
    
    printf("\nElements of the list before sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    for(i=0;i<n-1;i++)
    {
        int flag = 1;
        for(j=0;j<n-i-1;j++)
        {
            operationsCount++;
            if(arr[j] > arr[j+1])
            {
                swapCount++;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 0;
            }
        }
        if(flag==1)
            break;
    }

    printf("\nElements of the list after sorting: ");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\nTotal Operations: %d\nTotal Swapcount: %d",operationsCount,swapCount);
}