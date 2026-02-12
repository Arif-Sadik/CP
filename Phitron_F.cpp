#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-30
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> n >> k;
    vector<ll> w(n);
    for (ll i = 0; i < n; i++)
        cin >> w[i];
    vector<ll> div;
    for (ll i = 1; i * i <= k; i++)
    {
        if (k % i == 0)
        {
            div.push_back(i);
            if (i * i != k)
                div.push_back(k / i);
        }
    }
    bool poss = false;
    for (ll tg : div)
    {
        ll cSum = 0;
        ll left = 0;
        for (ll right = 0; right < n; right++)
        {
            cSum += w[right];

            while (cSum > tg && left <= right)
            {
                cSum -= w[left];
                left++;
            }

            if (cSum == tg)
            {
                poss = true;
                break;
            }
        }
        if (poss)
            break;
    }

    if (poss)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}