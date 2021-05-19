#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[1000];
    scanf("%s",str);
    int i,index=0,j;    
    for(i=0;i<strlen(str);i++)
    {
        for(j=0;j<i;j++)
            if(str[i] == str[j])
                break;
        if(i==j)
            str[index++] = str[i];
    }
    str[index] = '\0';
    //printf("%s\n",str);
    for(i=0;i<index-1;i++)
    {
        for(j=i+1;j<index;j++)
        {
            if(str[i] > str[j])
            {
                char ch = str[i];
                str[i] = str[j];
                str[j] =ch;
            }
        }
    }
    printf("%s",str);
    return 0;
}
