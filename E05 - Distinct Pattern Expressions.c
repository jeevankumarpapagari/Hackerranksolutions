#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

char s[200005];
int a[256];
int main()
{
    scanf("%s",s);
    int l=strlen(s);
    long long ans=1;
    for(int i=0;i<l;i++)
    ans=ans+i-a[s[i]],a[s[i]]++;
    printf("%lld",ans);
    return 0;
}
