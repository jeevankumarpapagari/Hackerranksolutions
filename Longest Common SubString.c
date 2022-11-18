#include<stdio.h>
#include<string.h>

int main()
{
	char s1[100], s2[100];
	printf("Enter two strings: ");
	scanf("%s %s",s1,s2);

	int l1 = strlen(s1), l2 = strlen(s2), lcs = 0;
	char grid[l1+1][l2+1];

	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
		{
			grid[i][j] = (i==0||j==0) ? 0 : s1[i-1]==s2[j-1] ? grid[i-1][j-1]+1 : 0;
			if(lcs < grid[i][j])
				lcs = grid[i][j];
		}
	}

	for(int i=0;i<=l1;i++)
	{
		for(int j=0;j<=l2;j++)
			printf("%d ",grid[i][j]);
		printf("\n");
	}
	printf("%d",lcs);
	return 0;
}
