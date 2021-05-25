#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[100], c ;
    scanf("%s",str);
    int i = 0, vowelCount = 0;
    while(str[i])
    {
        c = str[i];
        if(c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u')
            vowelCount++;
        i++;
    }
    printf("%.4f",((float)vowelCount/strlen(str))*100);
    return 0;
}
