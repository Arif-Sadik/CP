#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-09-30
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,x, c, s, d, t;
    cin>>t;

    while(t--)
    {
        s=1;
        cin>>n;
        if (n==0)
        {
            cout<<"0\n";
            continue;
        }
        for (ll i=1; i<=n; i++)
        {
            s*=i;
        }
        cout<<s%10<<endl;
        
        
    }

    return 0;
}