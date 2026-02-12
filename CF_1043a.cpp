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
    ll n,m,k,x, c, s, d, t;
    cin>>t;
    while(t--)
    {
        c=0, s=0, d=0;
        cin>>n;
        string sa,sb,sc;
        cin>>sa;
        cin>>m;
        cin>>sb;
        cin>>sc;
        string fr,bc, ans;
        for(ll i = 0; i < m; i++) {
            if (sc[i]=='V')
            {
                fr.push_back(sb[i]);
            }
            else bc.push_back(sb[i]);
        }

        reverse(fr.begin(), fr.end());
        ans=fr+sa+bc;
        cout<<ans<<endl;

        
        
    }

    return 0;
}