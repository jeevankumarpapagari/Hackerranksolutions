#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() 
{
    int xa,ya,xb,yb;
    scanf("%d%d%d%d",&xa,&ya,&xb,&yb);
    int xp,yp,xq,yq;
    scanf("%d%d%d%d",&xp,&yp,&xq,&yq);
    if(xb-xa==0 || xq-xp==0)    printf("no");
    else
    {
        if((float)(yb-ya)/(float)(xb-xa) == (float)(yq-yp)/(float)(xq-xp))  printf("yes");
        else                                                                printf("no");
    }
    return 0;
}
