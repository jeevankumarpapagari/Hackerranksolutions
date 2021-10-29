#include<stdio.h>
#include<stdlib.h>
//Defining property of activities
struct activity
{
    int actNO;
    int startTime;
    int endTime;
};
//Code for sorting data based on ending time of activity
int compare(const void *a,const void *b)
{
    return (((struct activity*)a)->endTime) - (((struct activity*)b)->endTime);
}

int main()
{
    //O(1)
    int n;  
    printf("How many activities information you want to store: ");
    scanf("%d",&n);

    //O(n)
    struct activity actList[n];
    int i,j;
    for(i=0;i<n;i++)
    {
        actList[i].actNO = i+1;
        printf("Enter %d activity beginning time and finishing time: ",actList[i].actNO);
        scanf("%d %d",&actList[i].startTime,&actList[i].endTime);
    }

    /*for(i=0;i<n;i++)
        printf("%d=> %d %d\n",actList[i].actNO,actList[i].startTime,actList[i].endTime);*/
    
    //O(nlogn)
    qsort(actList,n,sizeof(struct activity),compare);

    //O(n)
    printf("After sorting activities based on ending time: \n");
    for(i=0;i<n;i++)
        printf("%d=> %d %d\n",actList[i].actNO,actList[i].startTime,actList[i].endTime);
    
    //O(n)
    printf("Final Activities list:\n");
    i = 0;
    printf("Activilty No: %d\n",actList[i].actNO);
    for(j=1;j<n;j++)
    {
        if(actList[j].startTime >= actList[i].endTime)
        {
            printf("Avtivity No: %d\n",actList[j].actNO);
            i = j;
        }
    }
    //Total TIme complexity: O(1) + O(n) + O(nlogn) => O(nlogn)[Highiest]
    return 0;
}
