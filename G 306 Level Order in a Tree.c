/*

Level order traversal of a tree is obtained by doing a breadth first search on it.

You are given a tree with N nodes and N-1 edges. Each edge is bidirectional and connects two nodes.

The nodes of the tree are indexed from 1 to N and you can consider 1 to be the root of the tree.

You are given an integer d. Your task is to print the number of nodes that are present at the dth level of the tree.

It is guaranteed that atleast one node will be present at the dth level.

Input

First line contains n the number of nodes
Next n - 1 lines each contain two integers u and v such that there is an edge between u and v
Last line contains the integer d

Output

Print one number, the count of nodes at dth level of the tree

Sample Input 0

20
11 1
1 2
13 3
15 4
17 5
11 6
2 7
1 8
15 9
4 10
15 12
5 13
2 14
17 15
15 16
11 17
15 18
9 19
16 20
2

Sample Output 0

3


*/


#include<stdio.h>

int adj[1005][1005];
int v[1005], q[1005], d[1005], f = 0, r = -1;

void bfs(int s,int n)
{
    v[s] = 1;
    q[++r] = s;
    d[s] = 1;
    while(f <= r)
    {
        int x = q[f++], i;
        for(i=1;i<=n;i++)
        {
            if(adj[x][i] == 1 && v[i] == 0)
            {
                v[i] = 1;
                q[++r] = i;
                d[i] = d[x] + 1;
            }
        }
    }
}

int main()
{
    int n, i;
    scanf("%d",&n);
 
    for(i=0;i<n-1;i++)
    {
        int s,d;
        scanf("%d %d",&s,&d);
        adj[s][d] = 1;
        adj[d][s] = 1;
    }
    
    int level;
    scanf("%d",&level);
    
    bfs(1,n);
    
    int count = 0;
    for(i=1;i<=n;i++)
        if(d[i] == level)
            count++;
    
    printf("%d",count);
    return 0;
}
