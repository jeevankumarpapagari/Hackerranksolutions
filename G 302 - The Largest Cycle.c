/*

Problem statement: You are given a maze with N cells. Each cell may have multiple entry points but not more than one exit (ie. entry/exit points are unidirectional doors like valves). The cells are named with an integer value from 0 to N-1. You need to find the following :

The length of the largest cycle in the maze. Return 0 if there are no cycles.

Note: Aim for O(N) solution.

INPUT FORMAT
First line has the number of cells N

Second line has list of N values of the edge[] array. edge[i] contains the cell number that can be reached from of cell ‘i’ in one step. edge[i] is -1 if the ‘i’th cell doesn’t have an exit.

OUTPUT FORMAT
Length of the largest cycle.

Sample Input 0

5
1 2 3 0 2

Sample Output 0

4

*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int adj[1005][1005];

int bfs(int s,int n)
{
    int v[1005] = {0}, d[1005] = {0}; 
    int q[1005], f = 0, r = -1;
    int max = 0, i;
    v[s] = 1;
    q[++r] = s;
    d[s] = 0;
    while(f <= r)
    {
        int x = q[f++];
        for(i=0;i<n;i++)
        {
            if(adj[x][i] == 1)
            {
                if(v[i] == 1 && i!=x)
                    if(max < d[x]-d[i]+1)
                        max = d[x]-d[i]+1;
                if(v[i] == 0)
                {
                    v[i] = 1;
                    q[++r] = i;
                    d[i] = d[x] + 1;
                }
            }
        }
    }
    return max;
}

int main() 
{
    int n;
    scanf("%d",&n);
    
    int newEdge, i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&newEdge);
        if(newEdge != -1)
            adj[i][newEdge] = 1;
    }
    
    int max = 0;
    for(i=0;i<n;i++)
    {
        int temp = bfs(i,n);
        if(max < temp)
            max= temp;
    }
    printf("%d",max);
    return 0;
}
