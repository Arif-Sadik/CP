#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-09
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, x, c, s, d, t;
    cin >> n;
    ll mn = 1e9;
    bool f = false;
    while (n--)
    {
        ll k;
        cin >> k;
        if (abs(k) % 2 == 0)
        {
            mn = min(mn, abs(k));
            c = mn / 2;
            f = true;
        }
    }
    if (!f)
    {
        cout << "-1\n";
    }
    else
        cout << c << endl;

    return 0;
}