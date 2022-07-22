/*
Kefa was travelling in a one directional axis. He started at X = 0.
Petya had given Kefa the directions in the form of a string of '+'s and '-'s.
A '+' denoted that Kefa is supposed to move one unit in the positive direction.
Similarly, a '-' denoted that Kefa is supposed to move one unit in the negative direction.

Unfortunately, Kefa forgot some parts of the directions given to him by Petya, these parts are denoted by the character '?'.
Whenever Kefa has to process a '?', he tosses a coin. If heads, he moves one unit in the positive direction and if tails he moves one unit in the negative direction.

You are given the actual directions given by Petya and the directions that Kefa remembers.

Your task is to calculate the probability that Kefa will end up in the correct position.
Input

Input consists of two lines.
First line contains the string denoting the actual directions
Second line contains the string denoting the directions that Kefa remembers
Output

Print the probability that Kefa ends up in the correct final position
Notes

Length of the strings do not exceed 10

Sample Input 0

++-+-
+-+-+

Sample Output 0

1.000000


*/


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s1[15], s2[15] ;

    scanf("%s\n%s",s1,s2);

    int n = strlen(s1) ;
    
    int answerPosition = 0 ;
    for(int i=0;i<n;i++)
        answerPosition += (s1[i]=='+'?1:-1) ;

    int finalPosition = 0 ;
    int moves = 0 ; 
    for(int i=0;i<n;i++)
    {
        if(s2[i]=='?')
            moves++ ;
        else
            finalPosition += (s2[i]=='+'?1:-1) ;
    }

    int distance = answerPosition-finalPosition ;
    double answer ;
    if((distance+moves)%2!=0 || moves<abs(distance)) 
        answer = 0 ;
    else
    {
        int m = (moves+abs(distance))/2 ; 
        int c = 1 ;
        for(int i=0;i<m;i++)
            c *= moves-i ;
        for(int i=2;i<=m;i++)
            c /= i ;
        answer = (double)c/(1<<moves) ;
    }

    printf("%.12f\n", answer) ;

    return 0 ;
}
