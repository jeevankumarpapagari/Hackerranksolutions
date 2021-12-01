#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n][n];
    
    int top = 0, bottom = n-1, left = 0, right = n-1, i, j = 1;
    
    while(1)
    {
        if(left > right)   break;
        
        for(i=left;i<=right;i++)    arr[top][i] = j++;
        
        top++;
        
        if(top > bottom)    break;
        
        for(i=top;i<=bottom;i++)    arr[i][right] = j++;
        
        right--;
        
        if(left > right)    break;
        
        for(i=right;i>=left;i--)    arr[bottom][i] = j++;
        
        bottom--;
        
        if(top > bottom)    break;
        
        for(i=bottom;i>=top;i--)    arr[i][left] = j++;
        
        left++;
    }
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            printf("%d ",arr[i][j]);
        printf("\n");
    }
    return 0;
}
