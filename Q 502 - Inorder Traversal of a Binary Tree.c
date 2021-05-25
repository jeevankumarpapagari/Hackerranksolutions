#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void inOrder(int arr[],int left,int right,int n)
{
    if(left>=0 && right<=n && left<=right && arr[left]!=0)
    {
        inOrder(arr,2*left,right,n);
        printf("%d ",arr[left]);
        inOrder(arr,2*left+1,right,n);
    }
}

int main() 
{
    int n;
    scanf("%d",&n);
    int bstArr[n+1], i;
    for(i=1;i<=n;i++)
        scanf("%d",&bstArr[i]);
    inOrder(bstArr,1,n,n);
    return 0;
}
