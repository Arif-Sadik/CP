#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-08-21
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k, c,  d, t;
    cin>>t;
    while(t--)
    {
        c=0, d=10;
        cin>>n;
        vector<ll>vc;
        string s=to_string(n);

        for(ll i = 1; i <=s.size(); i++) {
            c=d+1;
            if (n%c==0)
            {
                vc.push_back(n/c);
            }
            d*=10;
        }
        if (!vc.empty())
        {
            cout<<vc.size()<<endl;
            sort(vc.begin(), vc.end());
            for (auto x: vc)
            {
                cout<<x<<" ";
            }
            
        }
        else cout<<0;
        cout<<endl;
        
    }

    return 0;
}