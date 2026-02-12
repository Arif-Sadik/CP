#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

bool isSort(vector<ll> &vc)
{
    vector<ll> vc2;
    for (ll x : vc)
    {
        if (x < 10)
        {
            vc2.push_back(x);
        }
        else
        {
            string s = to_string(x);
            for (ll i = 0; i < s.size(); i++)
            {
                vc2.push_back(s[i] - '0');
            }
        }
    }
    for (ll i = 0; i < vc2.size() - 1; i++)
    {
        if (vc2[i] > vc2[i + 1])
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ll n, k, c, s, d, t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<ll> vc(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> vc[i];
        }

        if (isSort(vc))
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }

    return 0;
}