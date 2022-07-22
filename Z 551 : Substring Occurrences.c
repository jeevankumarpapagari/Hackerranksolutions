/*

Bug has a string S and a smaller string T. Bug needs to find how many times T occurs in S as a substring. Help him with the task.

Input Format

First line contains the string S. Second line contains the string T.

Constraints

1 <= |S| <= 100 1 <= |T| <= |S|

Output Format

Output the number of times T occurs in S.

Sample Input 0

bugsbunnywritesbuggycodes
bug

Sample Output 0

2

Explanation 0

bugs comes twice in the string S.
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char str[110], ss[110];
    scanf("%s\n%s",str,ss);
    
    int l1 = strlen(str), l2 = strlen(ss);

    int result = 0;
    for(int i=0;i<l1-l2+1;i++)
    {
        int j = i, k = 0, flag = 1;
        while(ss[k] != '\0')
        {
            if(str[j] != ss[k])
            {
                flag = 0;
                break;
            }
            j++; k++;
        }
        if(flag)
            result++;
    }
    printf("%d",result);
    return 0;
}
