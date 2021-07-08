#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int arr[1005][1005],n,state;

int get(int x,int y)
{
    if(state == 0)  return arr[x][y];
    if(state == 1)  return arr[y][n-x+1];
    if(state == 2)  return arr[n-x+1][n-y+1];
    return arr[n-y+1][x];
}


int main() 
{
    scanf("%d",&n);
    
    int i,j;
    
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            scanf("%d",&arr[i][j]);
    
    while(1)
    {
        char ch;
        scanf("%c",&ch);
        if(ch == '-')   
            break;
        else if(ch == 'Q')
        {
            int x,y;
            scanf("%d %d",&x,&y);
            printf("%d\n",get(x,y));
        }
        else if(ch == 'A')
        {
            int d;
            scanf("%d",&d);
            d = d / 90;
            state = (state-d) % 4;
            if(state < 0)
                state = state + 4;
        }
        else if(ch == 'U')
        {
            int x,y,z;
            scanf("%d %d %d",&x,&y,&z);
            arr[x][y] = z;
        }
    }
    return 0;
}
