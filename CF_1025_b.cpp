#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

long long c2(long long x)
{
    if (x <= 1)
        return 0;
    return ceil(log2(x));
}

int main()
{
    ll n, k, c, s, t;
    cin >> t;
    while (t--)
    {
        long long n, m, a, b;
        cin >> n >> m >> a >> b;
        ll x = n - a + 1;   //.
        ll y = m - b + 1;
        s=x+y;
        long long rowC = c2(min(a, x));
        long long colC = c2(min(b, y));

        cout << min(1 + c2(m) + rowC, 1 + c2(n) + colC) << '\n';
    }

    return 0;
}