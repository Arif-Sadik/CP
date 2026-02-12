#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n, k, x, c, s, d, t;
    cin >> n;
    k = n;
    map<ll, ll> mp;
    while (k--)
    {
        cin >> x;
        mp[x]++;
    }
    auto it = mp.rbegin();
    ll f = 0;
    while (it != mp.rend())
    {
        if ((*(it)).second % 2)
        {
            cout << "Conan";
            f = 1;
            break;
        }
        else
            it++;
    }
    if (!f)
        cout << "Agasa";

    return 0;
}