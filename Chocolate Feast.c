#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
	  int testcases;
    scanf("%d",&testcases);
	
    int N, M, C, i, now, temp;
    int answer[testcases];

    for(i=0;i<testcases;i++)
    {
		    scanf("%d %d %d",&N, &C, &M);
        temp = N/C;
        now=temp;
        answer[i]=temp;
        while (now>=M)
        {  
            answer[i] = answer[i] + (now/M);
            now=now - (now/M)*M + now/M;
        }
    }
	
    for(i=0;i<testcases;i++)
		printf("%d\n",answer[i]);
	  return 0;
}
