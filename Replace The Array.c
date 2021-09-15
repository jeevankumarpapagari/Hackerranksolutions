#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    int arr[n], i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    int max = arr[n-1];
    arr[n-1] = 0;
    
    for(i=n-2;i>=0;i--)
    {
        int temp = arr[i];
        arr[i] = max;
        if(max < temp)
            max = temp;
    }
    
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}
