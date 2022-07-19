/*

Assume 1 = A, 2 = B, 3 = C... 26 = Z and so on. Given a string of integers find out all the possible words that can made out of it in continuous order. For example take 1112. 1112 can be taken as (1)(1)(1)(2) = AAAB (11)(1)(2) = KAB (1)(11)(2) = AKB (1)(1)(12) = AAL ans so on.

print all the possible words that can be made out of it in ascending order.

Input Format

Only one number N.

Constraints

1 <= N <= 10^6

Output Format

Output all the words with one word one one line in ascending order.

Sample Input 0

112

Sample Output 0

AAB
AL
KB



*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char alphabets[] = "abcdefghijklmnopqrstuvwxyz";

void allPossible(char *number,int index,int n)
{
    static char s[50] = "";
    static int i = 0;
    
    if(index == n)
    {
        printf("%s\n",s);
        return;
    }
    
    int numFormed = number[index] - '0';
    
    if(numFormed > 0)
    {
        s[i++] = numFormed + 64;
        s[i] = '\0';
        allPossible(number,index+1,n);
        i--;
        if(n-index > 1)
        {
            numFormed = (number[index] - '0') * 10 + number[index+1] - '0';
            if(numFormed < 27)
            {
                s[i++] = numFormed + 64;
                s[i] = '\0';
                allPossible(number,index+2,n);
                i--;
            }
        }
    }
}

int main() 
{
    char number[50];
    scanf("%s",number);
    
    allPossible(number,0,strlen(number));
    
    return 0;
}
