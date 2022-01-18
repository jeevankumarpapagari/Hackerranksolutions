#include<stdio.h>
#include<stdlib.h>

struct job
{
    int jobId;
    float profit;
    int deadline;
};

int compare(struct job *x,struct job *y)
{
    return y->profit - x->profit;
}

int main()
{
    int n;
    printf("How many jobs are in queue? Answer: ");
    scanf("%d",&n);

    struct job jobList[n];
    int i, maxDeadline = 0;
    for(i=0;i<n;i++)
    {
        printf("Enter job details:jobid, Profit and deadline: ");
        scanf("%d %f %d",&jobList[i].jobId,&jobList[i].profit,&jobList[i].deadline);
        if(maxDeadline < jobList[i].deadline)
            maxDeadline = jobList[i].deadline;
    }

    qsort(jobList,n,sizeof(struct job),compare);//O(N logN)

    /*for(i=0;i<n;i++)
        printf("\n%d %f %d",jobList[i].jobId,jobList[i].profit,jobList[i].deadline);*/

    int jobSequenceList[maxDeadline];
    float totalProfit = 0.0;
    memset(jobSequenceList,0,maxDeadline*sizeof(int));//Assigning 0's into jobSequenceList

    for(i=0;i<n;i++)//O(N^2)
    {
        if(jobSequenceList[jobList[i].deadline-1] == 0)
        {
            jobSequenceList[jobList[i].deadline-1] = jobList[i].jobId;
            totalProfit = totalProfit + jobList[i].profit;
        }
        else
        {
            int j = jobList[i].deadline - 1;
            while(--j >= 0)
            {
                if(jobSequenceList[j] == 0)
                {
                    jobSequenceList[j] = jobList[i].jobId;
                    totalProfit += jobList[i].profit;
                    break; 
                }
            }
        }
    }

    for(i=0;i<maxDeadline;i++)
        if(jobSequenceList[i] != 0)
            printf("Job id => %d\n",jobSequenceList[i]);
    
    printf("\nFInal profit is: %f",totalProfit);

    /*
        Time Complexity: O(N^2)
            1. To sort: O(N LogN) [Minimum]
            2. To calculate: O(N^2) [Maximum]
    */
    return 0;
}
