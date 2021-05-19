#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char mainString[1000000],subString[1000000];
    gets(mainString);
    gets(subString);
    
    int l1 = strlen(mainString), l2 = strlen(subString), i, j;
    for(i=0;i<=l1-l2;i++)
    {
        for(j=0;j<l2;j++)
        {
            if(mainString[i+j] != subString[j])
                break;
        }
        if(j == l2)
        {
            printf("yes");
            return 0;
        }
    }
    printf("no");
    return 0;
}
