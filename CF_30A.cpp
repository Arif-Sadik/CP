#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-06
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> n;
        ll mx = -1e9;
        ll mn = 1e9;
        vector<ll>vc(n);
        for(ll i = 0; i < n; i++) {
            cin>>vc[i];
        }
        cin >> x;
        sort(vc.begin(),vc.end());

        //cout<<vc[0];

        if (x >= vc[0] && x <= vc[n-1])
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }

    return 0;
}