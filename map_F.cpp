#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,k,x, c, s, d, t;
        c=0, s=0, d=0;
        cin>>n;
        map<ll, ll> cnt;
        for(ll i = 0; i < n; i++) {
            cin>>x;
            cnt[x]++;
        }
        cout<<cnt.size()<<endl;
        

    return 0;
}