As simple as the title, given a number N, print the number of digits in N!

N! is defined as : N! = 1*2*3...(N-1)*N

0! = 0 and 1! = 1.

No number ever contains any leading zeros.

Input Format

Input contains only one number, N.

Constraints

1 <= N <= 1000

Output Format

Output one number that is equal to the number of digits in N!

Sample Input 0

6
Sample Output 0

3
Explanation 0

6! = 1x2x3x4x5x6 = 720 which has 3 digits. So the answer is 3.

Code:

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
/*
    log(a*b) = log(a) * log(b)
    log(n!) = log(1 * 2 * 3 ...... * n) 
*/
short numberOfDigits(short n)
{
    if(n<0)     return 0;
    if(n<=1)    return 1;
    double digits = 0;
    int i;
    for(i=2;i<=n;i++)
        digits += log10(i);
    return (short)(ceil(digits));
}
int main() 
{
    short n;
    scanf("%hd",&n);
    printf("%d",numberOfDigits(n));
    return 0;
}
