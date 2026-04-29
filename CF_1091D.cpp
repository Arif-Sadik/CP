#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-04-07
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;

        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }

        vector<int> p(k + 1);
        for (int i = 1; i <= k; i++)
        {
            cin >> p[i];
        }
        int target = a[p[1]];
        vector<int> cnt(k + 1, 0);

        cnt[0] += (a[1] != target);
        for (int i = 1; i < p[1]; i++)
        {
            cnt[0] += (a[i] != a[i + 1]);
        }
        for (int j = 1; j < k; j++)
        {
            for (int i = p[j]; i < p[j + 1]; i++)
            {
                cnt[j] += (a[i] != a[i + 1]);
            }
        }
        for (int i = p[k]; i < n; i++)
        {
            cnt[k] += (a[i] != a[i + 1]);
        }
        cnt[k] += (a[n] != target);
        int S = 0;
        int M = 0;
        for (int j = 0; j <= k; j++)
        {
            S += cnt[j];
            M = max(M, cnt[j]);
        }

        cout << max(M, S / 2) << "\n";
    }

    return 0;
}