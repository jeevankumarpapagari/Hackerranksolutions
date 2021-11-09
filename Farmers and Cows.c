#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int cmp(int *a,int *b)
{
    return *a-*b;
}
int search(int a[],int n,int k)
{
    int l=0,h=n-1;
    while(l<=h)
    {
      int mid=(l+h)/2;
      if(a[mid]==k)return 1;
      else if(a[mid]<k) l=mid+1;
       else h=mid-1;
    }
    return 0;
}
int main() {
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    qsort(a,n,sizeof(int),cmp);
    int c=0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(search(a,n,a[i]+a[j]))
                c++;
        }
    }
        printf("%d",c);
    return 0;
}
