#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-25
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, q, l, r;
    cin >> n;
    vector<ll> a(n), b(n), ax(n), bx(n);
    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b.begin(), b.end());
    ax[0] = a[0];
    bx[0] = b[0];

    for (ll i = 1; i < n; i++)
    {
        ax[i] = ax[i - 1] + a[i];
        bx[i] = bx[i - 1] + b[i];
    }
    cin >> m;
    while (m--)
    {
        cin >> q >> l >> r;
        if (q == 1)
        {
            if (l == 1)
            {
                cout << ax[r - 1] << endl;
                continue;
            }
            cout << ax[r - 1] - ax[l - 2] << endl;
        }
        else
        {
            if (l == 1)
            {
                cout << bx[r - 1] << endl;
                continue;
            }
            cout << bx[r - 1] - bx[l - 2] << endl;
        }
    }

    return 0;
}