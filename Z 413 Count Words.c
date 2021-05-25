#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	char str[10000];
    scanf("%[^\n]s",str);
    
    int wordCount = 0, i=-1;
    while(str[++i])
        if(str[i] == ' ')   wordCount++;
    printf("%d",wordCount+1);
	return 0;
}
