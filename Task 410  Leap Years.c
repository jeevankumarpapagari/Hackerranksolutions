#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char** leapyears (int arr[], int size)
{
	//declare dynamically an array of strings result
    char **result = malloc(sizeof(char*)*size);
    int i;
    for(i=0;i<size;i++)
        result[i] = malloc(4);//yes / no
        
	char yes[] = "yes";
	char no[] = "no";

	for (i = 0; i < size; i++)
	{
		if (arr[i]%4==0) strcpy(result[i], yes); //replace the '_' with proper condition
		else strcpy(result[i], no);
	}
	return result;
}	
int main()
{
    int i, N;
    scanf("%d", &N);
    int arr[N];
    for (i = 0; i < N; i++) scanf("%d", &arr[i]);
    char** ans = leapyears(arr, N);
    for (i = 0; i < N; i++) puts(ans[i]);
    return 0;
}
