#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-07
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> n >> k;
        string s;
        cin >> s;
        map<char, ll> mp;
        for (ll i = 0; i < n; i++)
        {
            mp[s[i]]++;
        }
        for (auto it : mp)
        {
            if (it.second % 2 != 0)
            {
                c++;
            }
        }
        if (c == 1 || c <= k+1)
        {
            cout << "Yes\n";
        }
        else
            cout << "No\n";
    }

    return 0;
}