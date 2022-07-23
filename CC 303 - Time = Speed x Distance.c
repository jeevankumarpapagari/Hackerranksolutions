/*

You are given a graph with N nodes and M edges. There may be multiple edges between the same pair of nodes and there may be self loops. Nodes are indexed from 1 to N. Mario resides in node indexed P while Luigi lives in the node with index Q. It takes T amount of time to go from one node to an adjacent node. Your task is to calculate the minimum time that it will take for Mario to go visit Luigi.
Input

First line contains 5 integers : N, M, P, Q, T.
Next M lines each contain two integers U and V denoting an edge between the vertex with index U and the vertex with index V.
Output

Print the minimum time it takes for mario to go meet luigi
If it is not possible for mario to go visit luigi, print -1.
Notes

All input values are less than or equal to 1000

Sample Input 0

5 6 1 5 2
1 2
1 3
1 4
2 4
3 4
4 5

Sample Output 0

4


*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int  adj[1005][1005],v[1005],dist[1005],queue[1005];
int n,m,p,q,t,f=0,r=-1;

void bfs(int s)
{
    if(s==q)
    {
        printf("0"); 
        return;
    }
    v[s]=1; 
    queue[++r]=s; 
    dist[s]=0;
    while(f<=r)
    {
        int x=queue[f++];
        for(int i=1;i<=n;i++)
        {
            if(adj[x][i]==1 && v[i]==0)
            {
                v[i]=1; 
                queue[++r]=i; 
                dist[i]=dist[x]+1;
                if(i==q)
                    break;
            }
        }
    }
    if(dist[q]==0)
        printf("-1");
    else 
        printf("%d",dist[q]*t);
}

int main()
{
    scanf("%d %d %d %d %d",&n,&m,&p,&q,&t);
    for(int i=0;i<m;i++)
    {
        int x,y; 
        scanf("%d%d",&x,&y);
        adj[x][y]=1;
        adj[y][x]=1;
    }
    bfs(p);
    
    return 0;
}
