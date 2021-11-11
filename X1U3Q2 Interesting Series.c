#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int n1,n2,n3;

int series(int n)
{
    return n==0 ? n1 : n==1 ? n2 : n==2 ? n3 : series(n-1)^series(n-2)+series(n-3);
}

int main() 
{
    int n;
    scanf("%d %d %d %d",&n1,&n2,&n3,&n);
    
    printf("%d",series(n));
    return 0;
}
