/*

FIND THE SUM OF THE MAXIMUM SUBARRAY.

Input Format

First line contains N value denoting number of integers

Next line contains N integers seperated by a space.

Constraints

1<=N<1000000

-10000<=a[i]<=10000

Output Format

A single integer denoting sum of the maximum sub array

Sample Input 0

8
-1 2 4 -3 5 2 -5 2

Sample Output 0

10



*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    int arr[n], i;
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    
    int max = INT_MIN, sum = 0;
    for(i=0;i<n;i++)
    {
        sum += arr[i];
        if(max < sum)
            max = sum;
        if(sum < 0)
            sum = 0;
    }
    printf("%d",max);
    return 0;
}
