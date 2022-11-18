#include<stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	printf("Enter value of n: ");
	scanf("%d",&n);

	int arr[n], result[n], i, j, max = 0;
	printf("Enter elements into an array: ");
	for(i=0;i<n;i++)
	{
		scanf("%d",&arr[i]);
		result[i] = 1;
	}

	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
			if(arr[j] < arr[i] && result[j]+1 > result[i])
				result[i] = result[j]+1;
		if(max < result[i])
			max = result[i];
	}
	printf("%d",max);
	return 0;
}
