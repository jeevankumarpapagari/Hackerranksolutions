#include<stdio.h>
int main()
{
    int n;
    printf("Enter n value:");
    scanf("%d",&n);

    int arr[n],i;
    printf("Enter values into an array:");
    for(i=0;i<n;i++)    scanf("%d",&arr[i]);

    int max = arr[0];
    int min = arr[0];

    for(i=0;i<n;i++)
    {
        if(max < arr[i])    max = arr[i];
        if(min > arr[i])    min = arr[i];
    }
    printf("\n\nMAx value: %d\n\nMin value: %d",max,min);

    int secondMax;
    //14 21 45 36 96
    if(arr[0] > arr[1])
    {
        max = arr[0];
        secondMax = arr[1];
    }
    else
    {
        max = arr[1];
        secondMax = arr[0];
    }
    for(i=2;i<n;i++)
    {
        if(max < arr[i])
        {
            secondMax = max;
            max = arr[i];
        }
        else if(secondMax < arr[i])
            secondMax = arr[i];
    }
    printf("\n\nMAx value: %d\n\nSecond Max value: %d",max,secondMax);
    return 0;
}