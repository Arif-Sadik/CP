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
    ll n, k, x, c, d, t;
    string s;
    cin >> s;
    if (s.size() >= 2)
    {
        n = 10 * s[s.size() - 2] + s[s.size() - 1];
    }
    else
        n = s[0];

    vector<ll> v2 = {6, 2, 4, 8};
    vector<ll> v3 = {1, 3, 9, 7};
    vector<ll> v4 = {6, 4, 6, 4};
    x = n % 4;
    c = 1 + v2[x] + v3[x] + v4[x];
    cout << c % 5;

    return 0;
}