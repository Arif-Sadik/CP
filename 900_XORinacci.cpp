#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-02-01

ll fun(ll n, ll a, ll b)
{
    if (n % 3 == 2)
    {
        return a ^ b;
    }
    else if (n % 3 == 0)
    {
        return a;
    }
    else
    {
        return b;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t;
    cin >> t;
    while (t--)
    {
        ll a, b;
        cin >> a >> b >> n;
        cout << fun(n, a, b) << "\n";
    }

    return 0;
}