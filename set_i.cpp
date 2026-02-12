#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n, m, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        set<ll> A;
        set<ll> B;
        set<ll> C;
        cin >> n;
        cin >> m;
        while (n--)
        {
            cin >> x;
            A.insert(x);
        }
        
        while (m--)
        {
            cin >> x;
            B.insert(x);
        }
        set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));

        cout << C.size() << "\n";
    }

    return 0;
}