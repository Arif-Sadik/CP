#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-04
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m, k, x, c = 0, s, d, t;
    cin >> n >> m;
    ll i = 1;
    while (n != 0)
    {
        c++;
        n--;
        if (i % m == 0)
        {
            n++;
        }
        i++;
    }
    cout << c << endl;

    return 0;
}