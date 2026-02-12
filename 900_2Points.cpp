#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-26
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c = 0, d, t;
    string s;
    cin >> n >> s;
    map<string, ll> mp;
    for (ll i = 0; i < n - 1; i++)
    {
        string sub = s.substr(i, 2);
        mp[sub]++;
    }
    for (auto it : mp)
    {
        if (it.second > c)
            c = it.second;
    }
    for (auto it : mp)
    {
        if (it.second == c)
        {
            cout << it.first << endl;
            break;
        }
    }

    return 0;
}