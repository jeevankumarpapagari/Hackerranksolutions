#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct Date
{
    int day, month, year;
};
typedef struct Date date;
int compare(const void* d1, const void* d2)
{
    if(((date*)d1)->year < ((date*)d2)->year)   return 1;
    if(((date*)d1)->year == ((date*)d2)->year && ((date*)d1)->month < ((date*)d2)->month)   return 1;
    if(((date*)d1)->year == ((date*)d2)->year && ((date*)d1)->month == ((date*)d2)->month && ((date*)d1)->day < ((date*)d2)->day)   return 1;
    return 0;
}

int main() 
{
    int n;
    scanf("%d",&n);
    struct Date arr[n];
    int i;
    for(i=0;i<n;i++)
        scanf("%d%d%d",&arr[i].day,&arr[i].month,&arr[i].year);
    qsort(arr,n,sizeof(arr[0]),compare);
    for(i=n-1;i>=0;i--)
    {
        /*if(arr[i].day < 10 && arr[i].month < 10)
            printf("0%d 0%d %d\n",arr[i].day,arr[i].month,arr[i].year);
        else if(arr[i].day >= 10 && arr[i].month < 10)
            printf("%d 0%d %d\n",arr[i].day,arr[i].month,arr[i].year);
        else if(arr[i].day < 10 && arr[i].month >= 10)
            printf("0%d %d %d\n",arr[i].day,arr[i].month,arr[i].year);
        else*/
            printf("%d %d %d\n",arr[i].day,arr[i].month,arr[i].year);
    }
        
    return 0;
}
