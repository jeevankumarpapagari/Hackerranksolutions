#include<stdio.h>

int min(int x,int y)
{
	return x<=y ? x : y;
}

int main(int argc, char const *argv[])
{
	
	int r,c;
	printf("Enter row and column information: ");
	scanf("%d %d",&r,&c);

	int arr[r][c], grid[r+1][c+1], i, j, result = 0;
	printf("Enter %d elements into an array: ",r*c);
	for(i=0;i<r;i++)
		for(j=0;j<c;j++)
			scanf("%d",&arr[i][j]);

	for(i=0;i<=r;i++)
	{
		for(j=0;j<=c;j++)
		{
			grid[i][j] = (i==0||j==0) ? 0 : arr[i-1][j-1]==1 ? min(min(grid[i-1][j],grid[i][j-1]),grid[i-1][j-1])+1 : 0;

			if(result < grid[i][j])
			result = grid[i][j];
		}
	}

	for(i=0;i<=r;i++)
	{
		for(j=0;j<=c;j++)
			printf("%d ",grid[i][j]);
		printf("\n");
	}
	printf("%d",result);
	return 0;
}
