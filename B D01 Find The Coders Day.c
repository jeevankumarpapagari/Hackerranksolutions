#include<stdio.h>
int main()
{
    int y, leap = 0;
    scanf("%d",&y);
    
    if(y%4==0)  leap = 1;
    if(y>1918)
    {
        if(y%100==0)   leap = 0;
        if(y%400==0)    leap = 1;
    }
    if(y!=1918)
        leap == 0 ? printf("13.09.%d\n",y) : printf("12.09.%d\n",y);
    else
        printf("26.09.%d\n",y);
    return 0;
}
