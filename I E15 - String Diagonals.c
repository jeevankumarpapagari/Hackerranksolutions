#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[100];
    scanf("%s",str);
    int len = strlen(str);
    int i=0,j=len-1,k;
    while(i <= j)
    {
        for(k=1;k<=i;k++)   printf(" ");
        printf("%c",str[i]);
        for(k=1;k<=j-i-1;k++)   printf(" ");
        if(i!=j)
            printf("%c",str[j]);
        i++;j--;
        printf("\n");
    }  
    while(i<len)
    {
        for(k=1;k<=j;k++)    printf(" ");
        printf("%c",str[j]);
        for(k=1;k<=i-j-1;k++)   printf(" ");
        printf("%c",str[i]);
        i++;j--;
        printf("\n");
    }

	return 0;
}
