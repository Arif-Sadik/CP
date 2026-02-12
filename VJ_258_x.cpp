#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-09-12
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,x, c, s, d, t;
    cin>>n>>k;
    set<ll>vc;
    for(ll i = 0; i < k; i++) {
        ll x;
        cin>>x;
        vc.insert(x);
    }

    for(ll i = n; ; i++) {
        ll temp=i;
        bool ok=true;
        while (temp)
        {
            if (vc.count(temp%10))
            {
                ok=false ;
                break;

            }
            temp/=10;
        }
        if (ok)
        {
            cout<<i;
            break;
        }
    }

    return 0;
}