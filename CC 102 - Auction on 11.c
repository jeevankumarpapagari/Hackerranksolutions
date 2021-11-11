#include<stdio.h>
int main() 
{
    int n; 
    scanf("%d",&n);
    long res=1;
    for(int i=1;i<=11;i++)
    {
        res=res*(n-11+i);
        res=res/i;
    }
    printf("%ld",res);
    return 0;
}
