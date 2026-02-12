#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k, x = 0;
        cin >> n;
        vector<ll> A(n), B(n);
        for (ll i = 0; i < n; ++i)
        {
            cin >> A[i];
        }
        for (ll i = 0; i < n; ++i)
        {
            cin >> B[i];
        }

        vector<ll> S(n + 2, 0), D(n + 2, 0);
        for (ll i = 0; i < n; ++i)
        {
            S[A[i]]++;
            S[B[i]]++;
            if (A[i] == B[i])
            {
                D[A[i]]++;
            }
        }

        ll uM = 0;
        while (uM <= n && S[uM] > 0)
        {
            ++uM;
        }

        vector<ll> can;
        for (ll x = 0; x <= n; ++x)
        {
            if (S[x] > 0 && D[x] == 0)
            {
                can.push_back(x);
            }
        }

        ll sS = n + 1;
        if (can.size() >= 2)
        {
            sort(can.begin(), can.end());
            sS = can[1];
        }

        ll answer = min(uM, sS);
        cout << answer << '\n';
    }

    return 0;
}