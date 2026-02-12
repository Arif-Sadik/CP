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
    
        cin>>n>>k;
        string s;
        cin>>s;
        ll c1=0;
        for(ll i = 0; i < n; i++) {
            if(s[i]=='1')
            {
                c1++;
            }
        }
        if (k>=c1)
        {
            cout<<"AliCe"<<endl;
            continue;
        }
        if(2*k<=n)
        {
            cout<<"BoB"<<endl;
            continue;

        }
        ll c0=0;
        bool k0=false;
        for(ll i = 0; i < n; i++) {
            if(s[i]=='0')
            {
                c0++;
            }
            else c0=0;
            if (c0>=k)
            {
                k0=true;
                break;
            }

        }
        if (k0)
        {
            cout<<"boB"<<endl;
        }
        else cout<<"AlIcE"<<endl;
        
        
    }

    return 0;
}