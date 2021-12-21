#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int compare(const void *x,const void *y)
{
    return *(int*)x - *(int*)y;
}

int main() 
{
    int n;
    scanf("%d",&n);
    
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    qsort(arr,n,sizeof(int),compare);
    
    int sum;
    scanf("%d",&sum);
    
    for(int i=0;i<n-2;i++)
    {
        int l = i+1, h = n-1;
        while(l < h)
        {
            if(arr[i]+arr[l]+arr[h] > sum)
                h--;
            else
            {
                for(int j=l+1;j<=h;j++)
                    printf("%d+%d+%d=%d\n",arr[i],arr[l],arr[j],arr[i]+arr[l]+arr[j]);
                l++;
            }
        }
    }
    return 0;
}
