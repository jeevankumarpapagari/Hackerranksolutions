#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
int t[1000000][2],s1[100000],s2[10000],t1=-1,t2=-1;
int main() {
    int n; scanf("%d",&n);
    int x,y;char c;
    for(int i=0;i<n-1;i++)
    {
        scanf("%d %d %c",&x,&y,&c);
        if(c=='L')t[x][0]=y;
        else t[x][1]=y;
    }
    s1[++t1]=1;
    while(t1!=-1||t2!=-1){
       while(t1!=-1)
       {
           int x=s1[t1--];
           printf("%d ",x);
           if(t[x][0])s2[++t2]=t[x][0];
           if(t[x][1])s2[++t2]=t[x][1];
       }
       while(t2!=-1)
       {
           int x=s2[t2--];
           printf("%d ",x);
           if(t[x][1])s1[++t1]=t[x][1];
           if(t[x][0])s1[++t1]=t[x][0];
       }
    }
    return 0;
}
