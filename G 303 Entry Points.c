#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    scanf("%d",&n); //Reading total number of nodes in the graph
    
    int edges[n], result[n], i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&edges[i]);
        result[i] = 0;
    }
    
    for(i=0;i<n;i++)
        result[edges[i]]++;
    
    int nodeValue = 0, max = result[0];
    for(i=1;i<n;i++)
    {
        if(max < result[i])
        {
            max = result[i];
            nodeValue = i;
        }
    }
    printf("%d",nodeValue);
    return 0;
}
