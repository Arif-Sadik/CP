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
        c=0, s=0, d=0;
        cin>>n>>x;
        vector<ll> a(n);
        vector<ll> b(n);
        for(ll i = 0; i < n; i++) {
            cin>>a[i];
        }
        for(ll i = 0; i < n; i++) {
            cin>>b[i];
        }
        sort(a.begin(),a.end());
        sort(b.rbegin(), b.rend());

        bool z=true;
        for(ll i = 0; i < n; i++) {
            if (a[i]+b[i]>x)
            {
                z=false;
                break;
            }
        }
        if (z) cout<<"Yes\n";
        else cout<<"No\n";
        
    }

    return 0;
}