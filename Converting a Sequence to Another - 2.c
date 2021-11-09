#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

long min(long x,long y)
{
    return x<y ? x : y;
}

long minOfThree(long x,long y,long z)
{
    return min(x,min(y,z));
}

int main() 
{
    int len1;
    scanf("%d",&len1);
    int arr[len1+1], i;
    for(i=1;i<=len1;i++)
        scanf("%d",&arr[i]);
    
    int len2;
    scanf("%d",&len2);
    int brr[len2+1], j;
    for(j=1;j<=len2;j++)
        scanf("%d",&brr[j]);
    
    long x,y,z;
    scanf("%ld %ld %ld",&x,&y,&z);
    
    long crr[len1+1][len2+1];
    
    for(i=0;i<=len1;i++)
        for(j=0;j<=len2;j++)
            crr[i][j] = i==0 ? j*x : j==0 ? i*y : arr[i]==brr[j] ? crr[i-1][j-1] : minOfThree(x+crr[i][j-1], z+crr[i-1][j-1], y+crr[i-1][j]);
    
    printf("%ld",crr[len1][len2]);
    
    return 0;
}
