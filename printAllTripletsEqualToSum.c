#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    int sum;
    scanf("%d",&sum);
    
    for(int i=0;i<n-2;i++)
        for(int j=i+1;j<n-1;j++)
            for(int k=j+1;k<n;k++)
                if(arr[i]+arr[j]+arr[k] == sum)
                    printf("%d + %d + %d = %d\n",arr[i],arr[j],arr[k],sum);
    return 0;
}
