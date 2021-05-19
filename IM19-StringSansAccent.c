#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[100000],c;
    scanf("%s",str);
    
    int i=-1;
    while(str[++i])
    {
        c = str[i];
        if(c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u')
            continue;
        else
            printf("%c",c);
    }
    return 0;
}
