#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-01-12
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;

        if (k > n)
        {
            cout << -1 << "\n";
            continue;
        }

        bool found = false;

        for (int i = 0; i <= 32; i++)
        {
            ll p = 1LL << i;

            if (p > n)
                break;

            ll val = n / p;
            ll rem = n % p;

            if (val < k && (val + 1) < k)
                break;

            if (val == k)
            {
                cout << i << "\n";
                found = true;
                break;
            }

            if (rem > 0 && (val + 1) == k)
            {
                cout << i << "\n";
                found = true;
                break;
            }
        }

        if (!found)
            cout << -1 << "\n";
    }

    return 0;
}