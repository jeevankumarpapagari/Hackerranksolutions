#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    char s1[101],s2[101];
    int i,c=0,j,m,n,p=0;
    scanf("%s%s",s1,s2);
    m=strlen(s1);
    n=strlen(s2);
    i=0;
    if(m==n)
    {
        if(!strcmp(s1,s2))
            c++;
    }
    else if(m>n)
    {
        i=0;
        
        for(i=0;i<=m-n;i++)
        {
            j=0;
            p=0;
            while(s2[j])
            {
                if(s1[i+j]!=s2[j])
                {
                    p=1;
                    break;
                    
                }
                j++;
            }
            if(p==0)
                c++;
            
        }
        
    }
    else
    {
        i=0;
         for(i=0;i<=n-m;i++)
        {
       
            j=0;
            p=0;
            while(s1[j])
            {
                if(s2[i+j]!=s1[j])
                {
                    p=1;
                    break;
                    
                }
                j++;
            }
            if(p==0)
                c++;
        }
    }
    printf("%d",c);
    return 0;
}
