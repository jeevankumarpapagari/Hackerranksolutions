#include<stdio.h>
int main()
{
    char str[100];
    scanf("%s",str);
    int i=0, count=0;
    while(str[i])//str[i]!='\0'
    {
        if(str[i] == '1')
            count++;
        else
        {
            printf("%d",count);
            count = 0;
        }
        i++;
    }
    printf("%d",count);
}
