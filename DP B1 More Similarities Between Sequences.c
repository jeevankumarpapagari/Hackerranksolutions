#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int max(int x,int y)
{
    return x>y ? x : y;
}

int main() 
{
    int len1;
    scanf("%d",&len1);
    int arr[len1], i;
    for(i=1;i<=len1;i++)
        scanf("%d",&arr[i]);
    
    int len2;
    scanf("%d",&len2);
    int brr[len2], j;
    for(j=1;j<=len2;j++)
        scanf("%d",&brr[j]);
    
    int crr[len1+1][len2+1];
    for(i=0;i<=len1;i++)
        for(j=0;j<=len2;j++)
            crr[i][j] = (i==0||j==0) ? 0 : arr[i]==brr[j] ? crr[i-1][j-1]+1 : max(crr[i-1][j],crr[i][j-1]);
    
    printf("%d",crr[len1][len2]);
    
    return 0;
}
