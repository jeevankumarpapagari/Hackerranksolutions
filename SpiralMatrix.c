#include<stdio.h>
int main()
{
    int arr[5][5] = {{1,2,3,4,5},{16,17,18,19,6},{15,24,25,20,7},{14,23,22,21,8},{13,12,11,10,9}};
    
    int top = 0, bottom = 4, left = 0, right = 4, i;
    
    while(1)
    {
        if(left > right)   break;
        
        for(i=left;i<=right;i++)    printf("%d ",arr[top][i]);
        
        top++;
        
        if(top > bottom)    break;
        
        for(i=top;i<=bottom;i++)    printf("%d ",arr[i][right]);
        
        right--;
        
        if(left > right)    break;
        
        for(i=right;i>=left;i--)    printf("%d ",arr[bottom][i]);
        
        bottom--;
        
        if(top > bottom)    break;
        
        for(i=bottom;i>=top;i--)    printf("%d ",arr[i][left]);
        
        left++;
    }
    return 0;
}
