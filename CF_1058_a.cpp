#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-12
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
        vector<ll>vc(n);
        vector<ll>fr(105,0);
        for(ll i = 0; i < n; i++) {
            cin>>vc[i];
            fr[vc[i]]++;
        }
        while (fr[c]>0)
        {
            c++;
        }
        cout<<c<<endl;
        
        
    }

    return 0;
}