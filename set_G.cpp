#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n, m, k, x, c, s, d, t;

    set<ll> A;
    set<ll> B;
    set<ll> C;
    cin >> n;
    while (n--)
    {
        cin >> x;
        A.insert(x);
    }
    cin >> m;
    while (m--)
    {
        cin >> x;
        B.insert(x);
    }
    set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));

    for (auto x : C)
    {
        cout << x << "\n";
    }

    return 0;
}