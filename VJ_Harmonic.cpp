#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-03
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,x, d, t;
    cin>>n;
    dubb s=0;
    for(ll i = 1; i <= n; i++) {
        s+=1.0/i;
    }
    cout<<fixed<<setprecision(4)<<s<<endl;

    return 0;
}