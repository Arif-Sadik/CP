#include <bits/stdc++.h>
#define ll long long
using namespace std;

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
        vector<ll> a(n), b(n);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll i = 0; i < n; i++)
            cin >> b[i];

        vector<ll> pre(n, -1e9);
        vector<ll> suf(n, -1e9);

        ll curr = a[0];
        pre[0] = curr;

        for (ll i = 1; i < n; i++)
        {
            curr = max(a[i], curr + a[i]);
            pre[i] = curr;
        }

        curr = a[n - 1];
        suf[n - 1] = curr;

        for (ll i = n - 2; i >= 0; i--)
        {
            curr = max(a[i], curr + a[i]);
            suf[i] = curr;
        }

        ll iB = pre[0];
        for (ll i = 1; i < n; i++)
        {
            iB = max(iB, pre[i]);
        }

        if (k % 2 == 0)
        {
            cout << iB << "\n";
            continue;
        }

        ll bestAdd = -1e9;

        for (ll i = 0; i < n; i++)
        {
            ll left = 0;
            if (i > 0)
                left = max(0LL, pre[i - 1]);

            ll right = 0;
            if (i < n - 1)
                right = max(0LL, suf[i + 1]);

            ll include_i = left + a[i] + right;
            ll after_add = include_i + b[i];
            bestAdd = max(bestAdd, after_add);
        }

        cout << max(iB, bestAdd) << "\n";
    }

    return 0;
}
