#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-01-12
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, t;
    cin >> t;
    while (t--)
    {
        cin >> n;

        if (n == 2)
        {
            cout << 2 << "\n";
        }
        else if (n == 3)
        {
            cout << 3 << "\n";
        }
        else if (n % 2 == 0)
        {
            cout << 0 << "\n";
        }
        else
        {
            cout << 1 << "\n";
        }
    }

    return 0;
}