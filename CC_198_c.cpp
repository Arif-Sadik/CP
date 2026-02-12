#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,k,x, c, s, d, t;
    cin>>t;
    while(t--)
    {
        bool b=false;
        c=0, s=0, d=0;
        ll a1,a2,b1,b2;
        cin>>a1>>b1>>a2>>b2;
        c=5*a1+b1;
        s=5*a2+b2;
        if (c>=s&&(c-s)%6==0)
        {
            b=true;
        }
        if (b)
        {
            cout<<"YeS"<<endl;
        }
        else cout<<"nO\n";
        
        
    }

    return 0;
}