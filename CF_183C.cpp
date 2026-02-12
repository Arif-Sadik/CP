#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-06
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, d, t;
    string s;
    cin >> t;
    while (t--)
    {
        cin >> n >> s;
        ll ca = 0, cb = 0;
        for (char ch : s)
        {
            if (ch == 'a')
                ++ca;
            else
                ++cb;
        }
        ll D = ca - cb;
        if (D == 0)
        {
            cout << 0 << '\n';
            continue;
        }
        map<ll, ll> firstPos;
        firstPos[0] = 0;
        ll cur = 0;
        ll best = n + 1;
        for (ll i = 1; i <= n; ++i)
        {
            cur += (s[i - 1] == 'a' ? 1 : -1);
            ll target = cur - D; // need prefix[j] == target
            auto it = firstPos.find(target);
            if (it != firstPos.end())
            {
                best = min(best, i - it->second);
            }
            // store earliest occurrence
            if (firstPos.find(cur) == firstPos.end())
                firstPos[cur] = i;
        }
        if (best == n)
            cout << -1 << '\n';
        else
            cout << best << '\n';
    }

    return 0;
}
