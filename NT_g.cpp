#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-14
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> n >> k;
    if (n == k)
    {
        cout << 1;
    }
    else if ((k - n) >= 10 || (k % 10 - n % 10) < 0)
    {
        cout << 0;
    }
    else
    {
        c = 1;

        for (ll i = k % 10; i > n % 10; i--)
        {
            c *= i;
        }
        cout << c % 10;
    }

    return 0;
}