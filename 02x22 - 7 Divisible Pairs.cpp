#include <bits/stdc++.h>
using namespace std;


int main() 
{
    int n, num;
    cin >> n;
    map<int, int> m;
    for(int i=0;i<n;i++)
    {
        cin >> num;
        m[num%7]++;
    }
    int result = m[0] * (m[0]-1)/2;
    result += m[1] * m[6];
    result += m[2] * m[5];
    result += m[3] * m[4];
    cout << result;
    return 0;
}
