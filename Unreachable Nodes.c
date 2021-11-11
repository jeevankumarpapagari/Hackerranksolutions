#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
vector<int> g[1005];
bool v[1005];
int n,m,x,y;
void dfs(int i)
{
    v[i]=1;
    for(auto j=g[i].begin();j!=g[i].end();j++)
        if(v[*j]==0)dfs(*j);
}
int main() {
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++)
    {
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int k;
    cin>>k;
    dfs(k);
    int c=0;
    for(int i=1;i<=n;i++)
        if(v[i]==0)c++;
    cout<<c;
    return 0;
}
