#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-03
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c = 1, s, d, t;
    vector<ll> p(30);
    p[0] = 1;
    x = 1;
    for (ll i = 1; i < 30; i++)
    {
        x*=2;
        p[i]=p[i-1]+ x;
        //cout<<p[i]<<" ";
    }
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> n;
        for(ll i = 1; i < 30; i++) {
            if (n%p[i]==0)
            {
                cout<<n/p[i]<<endl;
                break;
            }
        }
    }

    return 0;
}