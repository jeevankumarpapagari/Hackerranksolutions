#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void inOrder(char str[],int start,int end)
{
    if(end-start == 2)
        printf("%c%c%c",str[start],str[end],str[start+1]);
    else
    {
        int middle = (start+end)/2;
        inOrder(str,start,middle-1);
        printf("%c",str[end]);
        inOrder(str,middle,end-1);
    }
}

int main() 
{
    int str[1005];
    scanf("%s",str);
    inOrder(str,0,strlen(str)-1);
    return 0;
}
