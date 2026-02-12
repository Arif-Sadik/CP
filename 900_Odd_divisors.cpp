#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

bool power_of_2(ll n)
{
    return (n&(n-1))==0;
}

int main()
{
    ll n,k,x, c, s, d, t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        c=0, s=0, d=0;
        if(power_of_2(n))
        {
            cout<<"No\n";
        }
        else cout<<"Yes\n";
        
        
    }

    return 0;
}