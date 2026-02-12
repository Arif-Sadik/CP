#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{

    ll n, q;
    cin >> n >> q;

    vector<ll> x(n + 1);      
    vector<ll> prefix(n + 1);  

    for (ll i = 1; i <= n; ++i) {
        cin >> x[i];
        prefix[i] = prefix[i - 1] + x[i];
    }

    while (q--) {
        ll a, b;
        cin >> a >> b;
        cout << prefix[b] - prefix[a - 1] << '\n';
    }

    return 0;
}
