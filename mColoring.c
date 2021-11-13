#include<stdio.h>
#include<string.h>

int vc, mc;

//Print an output array
void printSolution(int color[vc])
{
    int i;
    for(i=0;i<vc;i++)
        printf("%d ",color[i]);
}

int isSafe(int graph[vc][vc],int color[vc])
{
    int i,j;
    for(i=0;i<vc;i++)
        for(j=0;j<vc;j++)
            if(graph[i][j]==1 && color[i]==color[j])
                return 0;
    return 1;
}

int isGraphColored(int graph[vc][vc],int m,int i,int color[vc])
{
    if(i == vc)
    {
        if(isSafe(graph,color))
        {
            printf("\nSolution Exists... Output: ");
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
    //Reading vertex count and m colors value 
    printf("Enter total number of Vertex count and Color count: ");
    scanf("%d %d",&vc,&mc);

    //Reading adjacency matrix value
    printf("\nEnter values [0 or 1] of an adjacency matrix:\n");
    int adm[vc][vc],i,j;
    for(i=0;i<vc;i++)
        for(j=0;j<vc;j++)
            scanf("%d",&adm[i][j]);
    
    //Fill all zero's into color array
    int color[vc];
    for(i=0;i<vc;i++)
        color[i] = 0;
    //memset(color,0,vc*sizeof(color[0]));

    //Checking if coloring is not possible
    if(!isGraphColored(adm,mc,0,color))
        printf("\nSolution does not exist");
    return 0;
}