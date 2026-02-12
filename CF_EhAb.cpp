#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-02-04
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,x, c, s, d, t;
    cin>>t;
    while(t--)
    {
        c=0, s=0, d=0;
        cin>>n;
        for(ll i = 0; i < n; i++) {
            ll m;
            cin>>m;
            if (m>0)
            {
                c+=m;
            }
            else s+=m;
        }
        if (abs(c)>=abs(s))
        {
            cout<<abs(c)-abs(s)<<"\n";
        }
        else cout<<abs(s)-abs(c)<<"\n";
        
        
    }

    return 0;
}