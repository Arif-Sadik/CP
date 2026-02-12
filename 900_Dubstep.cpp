#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-02
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c = 0, d, t;
    string s;
    cin >> s;
    n = s.size();
    while (c + 2 < n)
    {
        if (s[c] == 'W' && s[c + 1] == 'U' && s[c + 2] == 'B')
        {
            c += 3;
        }
        else
            break;
    }
    bool b = false;
    for (ll i = c; i < n; i++)
    {
        if (i <= (n - 3) && s[i] == 'W' && s[i + 1] == 'U' && s[i + 2] == 'B')
        {
            i += 2;
            if (!b)
            {
                // cout<<1;
                cout << " ";
            }
            b = true;
        }
        else
        {
            cout << s[i];
            b = false;
        }
    }

    return 0;
}