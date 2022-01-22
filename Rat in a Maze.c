bool isSafe(int maze[N][N], int x, int y) 
{ 
     // if (x,y outside maze) return false 
     if(x>=0 && x<N && y>=0 && y<N && maze[x][y]==1) 
          return true; 
     else      
          return false; 
}

void printSolution(int sol[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", sol[i][j]); 
        printf("\n"); 
    } 
}

bool solveMaze(int maze[N][N], int x, int y, int sol[N][N]) 
{ 
    if(x == N-1 && y == N-1) 
    { 
        sol[x][y] = 1; 
        return true; 
    } 
    // check if maze[x][y] is valid 
    if(isSafe(maze, x, y) == true) 
    { 
        sol[x][y] = 1; 

          // move forward in x direction
        if (solveMaze(maze, x+1, y, sol) == true) 
            return true;

      // if moving in x direction doesn't give solution then move down in y direction
      if (solveMaze(maze, x, y+1, sol) == true) 
           return true; 

      // BACKTRACK,
      // unmark x,y as part of solution path
      sol[x][y] = 0; 
      return false; 
    }    
    return false; 
} 


int main() 
{ 
    int maze[N][N]  =  { {1, 0, 0, 0}, 
        {1, 1, 0, 1}, 
        {0, 1, 0, 0}, 
        {1, 1, 1, 1} 
    }; 

    int sol[N][N] = { {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0}, 
        {0, 0, 0, 0} 
    };
    if (solveMaze(maze, 0, 0, sol) == false)
	printf("Solution doesn't exist"); 
    else
	printSolution(sol);
    return 0; 
} 
