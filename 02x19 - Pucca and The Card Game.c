#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    int arr[n],i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    int pucca = 0, garu = 0, l = 0, r = n-1, k = 1;
    while(l <= r)
    {
        if(k++%2)
            pucca = pucca + (arr[l] >= arr[r] ? arr[l++] : arr[r--]);
        else
            garu = garu + (arr[l] >= arr[r] ? arr[l++] : arr[r--]);
    }
    
    pucca >= garu ? printf("Pucca") : printf("Garu");
    return 0;
}
