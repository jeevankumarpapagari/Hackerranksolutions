#include<bits/stdc++.h>
using namespace std;
int main() 
{
    map<string,int> m;
    int n, i;
    cin >> n;
    for(i=1;i<=n;i++)
    {
        int op, marks;
        string name;
        cin >> op >> name;
        if(op == 1)
        {
            cin >> marks;
            m[name] += marks;
        }
        else if(op == 2)
        {
            if(m.find(name) != m.end())
                m.erase(name);  
        }                
        else
        {
            if(m.find(name) != m.end())
                cout << m[name] << endl;
            else
                cout << 0 << endl; 
        }     
    }
    return 0;
}
