#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-10
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,x, c, s=1, d, t;

    cin>>n>>k;
    x=min(n,k);
    for(ll i = 2; i <= x; i++) {
        s*=i;
        
    }
    cout<<s;

    return 0;
}