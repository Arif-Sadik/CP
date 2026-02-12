#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-02-02
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c = 1, s, d, t;
    cin >> x >> d;
    while (x <= d / 2)
    {
        c++;
        x *= 2;
    }
    cout<<c<<endl;

    return 0;
}