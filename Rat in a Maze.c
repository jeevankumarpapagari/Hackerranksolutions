#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

int n;

bool isSafeOfMazePosition(int maze[n][n],int r,int c)
{
    if(r>=0 && r<n && c>=0 && c<n && maze[r][c]==1)
        return true;
    else
        return false;
}

bool isMazeSolved(int maze[n][n],int r,int c,int sol[n][n])
{
    if(r==n-1 && c==n-1)
    {
        sol[r][c] = 1;
        return true;
    }
    
    if(isSafeOfMazePosition(maze,r,c))
    {
        sol[r][c] = 1;
        //Forward direction
        if(isMazeSolved(maze,r,c+1,sol))
            return true;
        //Downward direction
        if(isMazeSolved(maze,r+1,c,sol))
            return true;
        sol[r][c] = 0;
        return false;
    }
    
    return false;
}

void printSolution(int sol[n][n])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",sol[i][j]);
        printf("\n");
    }
}

int main() 
{
    scanf("%d",&n);
    
    int maze[n][n], sol[n][n], i, j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&maze[i][j]);
            sol[i][j] = 0;
        }
    }
    
    if(isMazeSolved(maze,0,0,sol))
        printSolution(sol);
    else
        printf("Solution doesnot exist");
    
    return 0;
}
