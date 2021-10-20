#include<stdio.h>
#include<string.h>

int vertexCount, chromaticNumber;

void printSolution(int color[vertexCount])
{
    int i;
    for(i=0;i<vertexCount;i++)
        printf("%d ",color[i]);
}

int isSafe(int graph[vertexCount][vertexCount],int color[vertexCount])
{
    int i,j;
    for(i=0;i<vertexCount;i++)
        for(j=0;j<vertexCount;j++)
            if(graph[i][j] && color[j]==color[i])
                return 0;
    return 1;
}

int isGraphColored(int graph[vertexCount][vertexCount],int m,int i,int color[vertexCount])
{
    if(i == vertexCount)
    {
        if(isSafe(graph,color))
        {
            printf("Solution Exists: ");
            printSolution(color);
            return 1;
        }
        return 0;
    }

    int j;
    for(j=1;j<=m;j++)
    {
        color[i] = j;
        if(isGraphColored(graph,m,i+1,color))
            return 1;
        color[i] = 0;
    }
    return 0;
}

int main()
{
    printf("Enter vertex count and chromatic number: ");
    scanf("%d %d",&vertexCount,&chromaticNumber);

    printf("\nEnter an adjacency matrix: ");
    int adjacencyMatrix[vertexCount][vertexCount], i,j;
    for(i=0;i<vertexCount;i++)
        for(j=0;j<vertexCount;j++)
            scanf("%d",&adjacencyMatrix[i][j]);
    
    int color[vertexCount];
    memset(color,0,vertexCount*sizeof(color[0]));

    if(!isGraphColored(adjacencyMatrix,chromaticNumber,0,color))
        printf("\nSolution does not exist");
    return 0;
}