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
        c=50000, s=0, d=0;
        cin>>n;
        vector<ll> vc(n);
        for(ll i = 0; i < n; i++) {
            cin>>vc[i];
        }
        for(ll i = 0; i < n-1; i++) {
            s=vc[i]+vc[i+1]/2;
            if (s<c)
            {
                c=s;
            }
        }
        for(ll i = 0; i < n; i++) {
            for(ll j = 0; j < n; j++) {
                if (i==j) continue;
                else if (vc[i]+vc[j]<c)
                c=vc[i]+vc[j];        
            }
        }
        cout<<c<<endl;
        
        
    }

    return 0;
}