#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[100];
    scanf("%s",str);
    int i;
    for(i=0;i<strlen(str)-1;i++)
    {
        if((str[i]==str[i+1]) || ((str[i]=='a'||str[i]=='e'||str[i]=='i'||str[i]=='o'||str[i]=='u'||str[i]=='y')&&(str[i+1]=='a'||str[i+1]=='e'||str[i+1]=='i'||str[i+1]=='o'||str[i+1]=='u'||str[i+1]=='y')))
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}
