#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char str[1000];
    scanf("%[^\n]s",str);
    
    int i = 0;
    
    while(str[++i])
        printf("%c",str[i]);
    printf("%c",str[0]);    
    
    return 0;
}
