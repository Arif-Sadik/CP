#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-10
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, d, t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        ll hh = stoi(s.substr(0, 2));
        ll mm = stoi(s.substr(3, 2));
        ll t = hh * 100 + mm;

        if (t == 0)
            cout << "00:00\n";
        else if (t <= 1111)
            cout << "11:11\n";
        else if (t <= 2222)
            cout << "22:22\n";
        else
            cout << "00:00\n";
    }

    return 0;
}