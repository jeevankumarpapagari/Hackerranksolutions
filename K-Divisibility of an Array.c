#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    long n, k;
    scanf("%ld %ld",&n,&k);
    
    long arr[k], i, newValue;
    
    memset(arr,0,sizeof(arr));
    
    for(i=0;i<n;i++)
    {
        scanf("%ld",&newValue);
        arr[newValue%k]++;
    }
    
    long result = arr[0] * (arr[0]-1)/2;
    
    for(i=1; i<=k/2&&i!=(k-i); i++)
        result += (arr[i] * arr[k-i]);
    
    if(k%2==0)
        result += (arr[k/2]*(arr[k/2]-1)/2);
    
    printf("%ld",result);
    
    return 0;
}
