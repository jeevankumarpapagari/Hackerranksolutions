/*
You are given two integer sequences A and B,

Your task is to make the sequence A exactly identical to B.

You can perform three operations on the sequence A :

    Insert an integer at some position
    Remove an integer from some position
    Modify an integer i.e. give a new value to an integer at some position

Every insertion operation costs x units.
Every removal operation costs y units.
Every modification operation costs z units

Your task is, given A and B, find the minimum cost to convert A to B.

Input

First line contains the number of elements in A
Second line contains the elements of the array A
Third line contains the number of elements in B
Fourth line contains the elements of the array B
Last line contains the integers x, y and z.

Output

Print the minimum cost of converting A to B

Notes

Size of the sequences will not exceed 1000
All elements of the sequences fit in a 32-bit integer.
Values of x, y and z will fil in a 32-bit integer.

Sample Input 0

6
1 2 3 4 5 6
8
1 5 7 2 8 4 5 6
5 5 10000

Sample Output 0

20


*/


#include<stdio.h>
long maze[1005][1005];

long min(long x,long y)
{
    return x<=y ? x : y;
}

 
int main() 
{
    
    int n, i; 
    scanf("%d",&n); 
    
    int a[n+1];
    for(i=1;i<=n;i++) 
        scanf("%d",&a[i]);
    
    int m, j;
    scanf("%d",&m); 
    int b[m+1];
    for(i=1;i<=m;i++) 
        scanf("%d",&b[i]);
    
    long x,y,z; 
    scanf("%ld %ld %ld",&x,&y,&z);
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            if(i==0)  
                maze[i][j]=j*x;
            else if(j==0)  
                maze[i][j]=i*y;
            else if(a[i]==b[j])  
                maze[i][j]=maze[i-1][j-1];
            else
                maze[i][j]=min(min(x+maze[i][j-1],y+maze[i-1][j]),z+maze[i-1][j-1]);
        }
    }
    printf("%ld",maze[n][m]);
    
    return 0; 
}
