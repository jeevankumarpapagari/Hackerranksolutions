#include <cmath>
#include <cstdio>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() 
{ 
    string str;
    int letters[26] = {0}, min = 10000, len=0;
    cin>>str;
    int lent = str.size();
    len = lent;
    for(int i=1; i<=lent; i++)
    {
        string temp = "";
        string ans = "";
        if(lent%i == 0)
        {
            for(int j=0; j<i; j++)
                ans+=str[j];
            for(int j=0; j<(lent/i); j++)
                temp+=ans;
            if(str==temp)
            {
                cout<<ans;
                return 0;
            }
        }
    }
    return 0;
}
