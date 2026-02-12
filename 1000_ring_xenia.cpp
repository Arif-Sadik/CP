#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-02-08
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> n >> x;
    vector<ll> vc(x);
    for (ll i = 0; i < x; i++)
    {
        cin >> vc[i];
    }
    s=vc[0]-1;
    for (ll i = 1; i < x; i++)
    {
        if (vc[i] >= vc[i - 1])
        {
            s += vc[i] - vc[i - 1];
        }
        else
            s += n - (vc[i-1] - vc[i]);
    }
    cout << s << endl;

    return 0;
}