#include<stdio.h>
int main()
{
    short n;
    scanf("%hd",&n);
    short arr[n],temp[n],i,j;
    for(i=0;i<n;i++) 
    {
        scanf("%hd",&arr[i]);
        temp[i] = -1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(i!=j && arr[i] == arr[j])
                temp[i] = abs(i-j);
        }
    }
    for(i=0;i<n;i++)    printf("%hd ",temp[i]);
	return 0;
}
