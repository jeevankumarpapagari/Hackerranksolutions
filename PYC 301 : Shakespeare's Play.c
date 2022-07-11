/*

Romeo and Juliet were reading the Shakespeare works. They got interested in the Play Romeo and Juliet. Since Juliet belongs to the Capulet Family, she reads only the capital case letters in the given text. And Romeo being a Montague reads only the small case letters. If all the letters read by Romeo and Juliet are concatenated into one sentence, and will contain all letters from Roman alphabet, they will win a trip to France, otherwise they will stay back in Italy.

They want to know if they have won or not, as they are busy in packing their luggage, as you are their common friend, should help them find if they have won or not. Given an English sentence, print "France" (without quotes) if all the Roman alphabets are read and print "Italy" (without quotes) otherwise

For example, if they read the following sentence:
abcdefghijklMNOPQRSTUVWXYZ
Juliet read : MNOPQRSTUVWXYZ Romeo read : abcdefghijkl
Since collectively they read all the alphabet letters you print "France"

Input Format
A single line with string S.

Constraints
1<= Length of the string <= 1000
each character of S, S[i] ∈ {a-z, A-Z, Space}

Output Format
print either France or Italy

Sample Input 0
The quick brown Fox jumps over the lazy dog

Sample Output 0
France

Explanation 0
Since all the Alphabet letters are read, France is printed

Sample Input 1
The quick Fox jumps over the lazy dog

Sample Output 1
Italy

Explanation 1
Since all alphabet letters are not there, Italy is printed Note: The letters b, n and w are missing
*/


#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main() 
{
    char str[1005];
    scanf("%[^\n]s",str);
    
    int chars[26] = {0}, i = -1;
    while(str[++i])
    {
        str[i] = tolower(str[i]);
        if(str[i]>=97 && str[i]<=122)
            chars[str[i]-'a'] = 1;
    }
    int sum = 0;
    for(i=0;i<26;i++)
        sum = sum + chars[i];
    
    sum == 26 ? printf("France") : printf("Italy");
        
    return 0;
}
