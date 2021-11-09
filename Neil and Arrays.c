#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int max(int a,int b){
    if(a>b) return a;
    return b;
}
int main() {
    int q,t,i,n,up,down,temp;
    scanf("%d",&t);
    for(q=0;q<t;q++){
        scanf("%d",&n);
        int arr[n];
        for(i=0;i<n;i++){
            scanf("%d",&arr[i]);
        }
       up=0;down=0;
        for(i=n-2;i>=0;i--){
            if(i==n-2)
            {
                up=up+arr[n-2]-1;
                down=down+arr[n-1]-1;
            }
            else{
                temp=up;
                up=max(arr[i]-1+down,arr[i]-arr[i+1]+up);
                down=max(arr[i+1]-1+temp,down);
            }
        }
        printf("%d\n",max(up,down));
    }
    return 0;
}
