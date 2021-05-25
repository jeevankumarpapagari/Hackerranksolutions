#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
int palindrome(char* str)
{
    char *temp = str;
    int len = 0;
    while(*temp)
    {
        len++;
        temp++;
    }
    
    int i=0,j=len-1;
    while(i<j)
    {
        if(*(str+i) != *(str+j))
            return 0;
        i++;
        j--;
    }
    return 1;
        
}	
int main()
{
  char str[50];
  gets(str);
  printf("%d", palindrome(str));
  return 0;
}
