#include <bits/stdc++.h>
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
    ll n, k, x, c = 0, s = 0, d, t;
    cin >> n;
    vector<ll> fact(10);
    fact[0] = 1;
    for (ll i = 1; i < 10; i++)
    {
        fact[i] = fact[i - 1] * i;
    }

    for (ll i = 10; i < n; i++)
    {
        x = i;
        s=0;
        while (x > 0)
        {
            s += fact[x % 10];
            x /= 10;
        }
        if (s % i == 0)
            c += i;
    }
    cout<<c;

    return 0;
}