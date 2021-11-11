#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
        b[i]=0;
        cin>>a[i];
    }
    for(int i=0;i<n;i++)
    {
        b[a[i]]++;
    }
    int m=0,j=0;
    for(int i=0;i<n;i++){
        if(b[i]>m){
            m=b[i];
            j=i;
        }
    }
    printf("%d",j);
    return 0;
}
