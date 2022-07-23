/*

Mario and Luigi's world have been turned upside down. The edges in their world are no more all of the same length. Each edge has its own length now.

You are given a graph with N nodes and M edges. There may be multiple edges between the same pair of nodes and there may be self loops. Nodes are indexed from 1 to N. Mario resides in node indexed P while Luigi lives in the node with index Q. It takes T amount of time to travel 1 kilometre. Your task is to calculate the minimum time that it will take for Mario to go visit Luigi.
Input

First line contains 5 integers : N, M, P, Q, T.
Next M lines each contain three integers U,V and W denoting an edge between the vertex with index U and the vertex with index V with weight W.
Note that the edges are bidirectional
Output

Print the minimum time it takes for mario to go meet luigi
If it is not possible for mario to go visit luigi, print -1.
Notes

All input values are less than or equal to 1000

Sample Input 0

5 6 1 5 2
1 2 1
1 3 2
1 4 3
2 4 1
3 4 1
4 5 1

Sample Output 0

6


*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#define inf 9999999

int cost[1005][1005];
int n,m,p,q,t,x,y,z;

int min(int a,int b)
{
    return a < b ? a : b;
}

int main() 
{
    scanf("%d%d%d%d%d",&n,&m,&p,&q,&t);
    for(int i=0;i<=n;i++)
        for(int j=0;j<=n;j++)
            if(i!=j)
                cost[i][j]=inf;

    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        if(cost[x][y]>z)
        {
            cost[x][y]=z;
            cost[y][x]=z;
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }
    if(cost[p][q]==inf)
        printf("-1");
    else 
        printf("%d",cost[p][q]*t);
    return 0;
}
