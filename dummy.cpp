#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-05-01
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll x, a, b, c, s;
    cin >> a >> b >> c;
    ll p1, p2;
    if (a == 1)
        x = 1;
    else if (b == 1)
        x = 2;
    else if (c == 1)
        x = 3;
    cin >> s;
    ll sm[] = {0, 0, 0};
    while (s--)
    {
        cin >> p1>> p2;
        if (p1 == x)
        {
            x = p2;
        }
        else if (p2==x)
        {
            x = p1;
        }
        sm[x-1]++;
    }
    for (ll i = 0; i < 3; i++)
    {
        cout <<sm[i] <<(i==2? "":" ");
    }

    return 0;
}