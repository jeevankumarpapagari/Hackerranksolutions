#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int adj[1000][1000], result[1000];

void dfs(int head,int n)
{
    result[head] = 1;
    for(int i=1;i<=n;i++)
    {
        if(adj[head][i]==1 && result[i]==0)
            dfs(i,n);
    }
}

int main() 
{
    int n, m, i;
    scanf("%d %d",&n,&m);//Reading nodes and edge count information
 
    for(i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        adj[x][y] = 1;
        adj[y][x] = 1;
    }//Preparing an adjacency matrix
    
    int head;
    scanf("%d",&head);//Reading head value
    
    dfs(head,n);
    
    int count = 0;
    for(i=1;i<=n;i++)
        if(result[i] == 0)
            count++;
    printf("%d",count);
    return 0;
}
