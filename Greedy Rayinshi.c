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
    
    int Rayinshi = 0, Neechea = 0, l = 0, r = n-1, k = 1;
    while(l <= r)
    {
        if(k++%2)
            Rayinshi = Rayinshi + (arr[l] >= arr[r] ? arr[l++] : arr[r--]);
        else
            Neechea = Neechea + (arr[l] >= arr[r] ? arr[l++] : arr[r--]);
    }
    
    printf("%d %d",Rayinshi,Neechea);
    return 0;
}
