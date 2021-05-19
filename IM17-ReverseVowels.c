#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    //Read string value into program
    char str[100000];
    scanf("%s",str);//0:J 1:e 2:e 3:v 4:a 5:n
    
    char vowels[100000],c;
    int i = 0, j = 0;
    
    //Extract all the vowels from main string into vowels string
    while(str[i])
    {
        c = str[i];
        if(c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u')
            vowels[j++] = str[i];
        i++;
    }
    //Copying vowels into main string in reverse order
    i = 0;
    while(str[i])
    {
        c = str[i];
        if(c=='A'||c=='a'||c=='E'||c=='e'||c=='I'||c=='i'||c=='O'||c=='o'||c=='U'||c=='u')
            str[i] = vowels[--j];
        i++;
    }
    printf("%s",str);
    return 0;
}
