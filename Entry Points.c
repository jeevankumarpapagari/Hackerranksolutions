/*

You are given a maze with N cells. Each cell may have multiple entry points but not more than one exit (ie. entry/exit points are unidirectional doors like valves). The cells are named with an integer value from 0 to N-1. You need to find the following :

find Maximum number of entry points (incoming edges) for any cell in the maze

Note: Aim for O(N) solution.

INPUT FORMAT
First line has the number of cells N

Second line has list of N values of the edge[] array. edge[i] contains the cell number that can be reached from of cell ‘i’ in one step. edge[i] is -1 if the ‘i’th cell doesn’t have an exit.

OUTPUT FORMAT
Print the index of node with max entry points

Sample Input 0

5
4 4 4 4 -1

Sample Output 0

4

*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n);
    
    int nodes[n], entryPoints[n], i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&nodes[i]);
        entryPoints[i] = 0;
    }
    
    for(i=0;i<n;i++)
        entryPoints[nodes[i]]++;
    
    int max = 0, nodeValue = 0;
    for(i=0;i<n;i++)
    {
        if(entryPoints[i] > max)
        {
            max = entryPoints[i];
            nodeValue = i;
        }
    }
    printf("%d",nodeValue);
    return 0;
}
