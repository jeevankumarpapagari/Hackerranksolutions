#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long long int t,i,j,k,sum,flag;
    cin>>t;
    for(i=0;i<t;i++)
    {
        int a[10][10];
        flag=0;
        for(j=0;j<9;j++)
        {
            sum=45;
            int b[10];
            for(k=0;k<9;k++)
            {
                cin>>a[j][k];
                sum=sum-a[j][k];
                b[k]=a[j][k];
            }
            if(sum!=0)
            {
                flag=1;
                break;
            }
            sort(b,b+9);
            if(b[0]==1 && b[1]==2 && b[2]==3 && b[3]==4 && b[4]==5 && b[5]==6 && b[6]==7 && b[7]==8 && b[8]==9)
            {
                
            }
            else
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
            cout<<"inValid"<<endl;
        else
        {
            for(j=0;j<9;j++)
            {
                int b[10],s[10];
                sum=45;
                for(k=0;k<9;k++)
                {
                    b[k]=a[k][j];
                    sum=sum-a[k][j];
                    s[k] = a[(j / 3) * 3 + k / 3][j * 3 % 9 + k % 3];

                }
                if(sum!=0)
                {
                    flag=1;
                    break;
                }
                sort(b,b+9);
                sort(s,s+9);
            if(b[0]==1 && b[1]==2 && b[2]==3 && b[3]==4 && b[4]==5 && b[5]==6 && b[6]==7 && b[7]==8 && b[8]==9 && s[0]==1 && s[1]==2 && s[2]==3 && s[3]==4 && s[4]==5 && s[5]==6 && s[6]==7 && s[7]==8 && s[8]==9 )
            {
                
            }
            else
            {
                flag=1;
                break;
            }
            }
            if(flag==1)
                cout<<"inValid"<<endl;
            else
                cout<<"Valid"<<endl;
        }
      
    }
    return 0;
}
