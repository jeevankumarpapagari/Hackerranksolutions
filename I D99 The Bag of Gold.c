#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct bag
{
    double w,p;
};
int cmp(struct bag *a,struct bag *b)
{
    double x=a->p/a->w;
    double y=b->p/b->w;
    if(x==y)return 0;
    else if(x>y)return -1;
    else return 1;
}

int main() 
{
    int n,m;
    scanf("%d%d",&n,&m);
    struct bag a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&a[i].w,&a[i].p);
    }
    qsort(a,n,sizeof(struct bag),cmp);
    int i=0;
    double p=0;
    
    while(i<n&&m>=a[i].w)
    {
        p=p+a[i].p;
        m=m-a[i].w;
        i++;
    }
    if(i<n&&m>0)
    {
        p=p+a[i].p*m/(double)a[i].w;
    }
    if(i==n&&m>0)
    {
        printf("-1");return 0;
    }
    printf("%.12lf",p);
    return 0;
}
