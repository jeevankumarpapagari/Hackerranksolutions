#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int n;
    char a[100000];
    
    for(n=1;gets(a);n++)
    {
        int i, j;
        double I = 0, V = 0, R = 0;
        char b[100000];
        
        for(i=0;a[i];i++)
        {
            if(a[i] == '=')
            {
                if(a[i-1] == 'I')
                {
                    int k = 0;
                    for(j=0;j<10;j++)
                    {
                        b[j] = a[i+k+1];
                        k++;
                    }
                    I = atoi(b);
                }
                if(a[i-1] == 'V')
                {
                    int k = 0;
                    for(j=0;j<10;j++)
                    {
                        b[j] = a[i+k+1];
                        k++;
                    }
                    V = atoi(b);
                }
                if(a[i-1] == 'R')
                {
                    int k = 0;
                    for(j=0;j<10;j++)
                    {
                        b[j] = a[i+k+1];
                        k++;
                    }
                    R = atoi(b);
                }
            }
        }
        if(I && V)
        {
            R = V/I;
            printf("R=%.2lfO",R);
        }
        else if(R && V)
        {
            I = V/R;
            printf("I=%.2lfA",I);
        }
        else if(I && R)
        {
            V = I*R;
            printf("V=%.2lfV",V);
        }
        printf("\n");
    }
    return 0;
}
