 #include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct edge
{
       int x, y, l;
};

int main()
{
       int n,e,i,j;
       scanf("%d%d",&n,&e);
       struct edge a[e],t;
       for(i=0;i<e;i++)
       {
              scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].l);
       }     
       for(i=0;i<e-1;i++)
       {
              for(j=i+1;j<e;j++)
              {
                     if(a[i].l > a[j].l)
                     {
                           t = a[i];
                           a[i] = a[j];
                           a[j] = t;
                     }
              }
       }
       int sum=0,s,vn[3002]={0},vi[n],vil,xz,yz;
       scanf("%d",&s);
       vi[0] = s;
       vil = 1;
       while(vil<n)
       {
              for(i=0;i<e;i++)
              {
                     xz = 0;
                     yz = 0;
                     if(vn[a[i].x] == 0 || vn[a[i].y] == 0)
                     {
                           for(j=0;j<vil;j++)
                           {
                                  if(a[i].x == vi[j])
                                  {
                                         xz++;               
                                  }
                                  if(a[i].y == vi[j])
                                  {
                                         yz++;
                                  }
                           }
                           if((xz==0 && yz!=0) || (yz==0 && xz!=0))
                           {
                                  sum = sum + a[i].l;
                                  if(xz==0)
                                  {
                                         vi[vil] = a[i].x;
                                         vil++;
                                         vn[a[i].x]++;
                                  }
                                  else
                                  {
                                         vi[vil] = a[i].y;
                                         vil++;
                                         vn[a[i].y]++;
                                  }
                                  i = -1;
                           }     
                     }
              }
       }
       printf("%d\n",sum);
    return 0;
}
