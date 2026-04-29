#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-04-13
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
        bool bl=true;
        vector<bool>b(101,false);
        vector<ll>vc(n);
        for(ll i = 0; i < n; i++) {
            cin>>vc[i];
            if (b[vc[i]]==true)
            {
                bl=false;
            }
            else b[vc[i]]=true;
        }
        if (!bl)
        {
            cout<<"-1\n";
        }
        else {
            sort(vc.rbegin(),vc.rend());
            for(ll i = 0; i < n; i++) {
                cout<<vc[i]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}