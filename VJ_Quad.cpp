#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-28

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    ll a, b;
    cin >> a >> b >> c;
    dubb z = (pow(b, 2) - 4 * a * c);
    if (z < 0)
    {
        cout << "No roots\n";
    }

    else
    {
        z = sqrt(z);
        if (floor(z) != z)
        {
            cout << "No roots\n";
            return 0;
        }

        n = (-b + z) / (2 * a);
        k = (-b - z) / (2 * a);
        if (n == k)
        {
            cout << "One root: " << n << endl;
        }
        else
            cout << "Two roots: " << k << " " << n << endl;
    }

    return 0;
}