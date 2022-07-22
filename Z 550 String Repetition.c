/*
Given a string, find the smallest string that can generate the original string by concatenation. See example case for clarity.

Input Format

One string. String is guaranteed to contain lowercase letters only.

Constraints

1 <= length of string <= 5000

Output Format

Print the smallest string that can be repeated to get the original string.

Sample Input 0

abababab

Sample Output 0

ab


*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    char str[5005];
    scanf("%s",str);
    int len = strlen(str);
    for(int i=1; i<=len; i++)
    {
        char temp[5005] = "", ans[5005] = "";
        int k = 0, l = 0;
        if(len%i == 0)
        {
            for(int j=0; j<i; j++)
                ans[k++] = str[j];
            ans[k] = '\0';
            for(int j=0; j<(len/i); j++)
            {
                int x = 0;
                while(ans[x])
                {
                    temp[l++] = ans[x++];
                }
                temp[l] = '\0';
            }
            //printf("%s %s\n",ans,temp);
            if(strcmp(str,temp) == 0)
            {
                printf("%s",ans);
                return 0;
            }
        }
    }
    return 0;
}
