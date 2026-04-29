#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-04-05

void MCM(vector<ll> &p, vector<vector<ll>> &m, vector<vector<ll>> &s)
{
    ll n = p.size() - 1; // num of matrix
    for (ll i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    for (ll L = 2; L <= n; L++)
    {
        for (ll i = 1; i <= n - L + 1; i++)
        {
            ll j = i + L - 1;
            m[i][j] = INT_MAX;
            for (ll k = i; k < j; k++)
            {
                ll q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}

void print(ll i, ll j, vector<vector<ll>> &s)
{
    if (i == j)
    {
        cout << "A" << i;
    }
    else
    {
        cout << "(";
        print(i, s[i][j], s);
        print(s[i][j] + 1, j, s);
        cout << ")";
    }
}

int main()
{
    ll n_dim; // num of element
    cin >> n_dim;
    vector<ll> p(n_dim);
    for (ll i = 0; i < n_dim; i++)
    {
        cin >> p[i];
    }

    ll n = n_dim - 1; // num of matrix
    vector<vector<ll>> m(n_dim, vector<ll>(n_dim, 0));
    vector<vector<ll>> s(n_dim, vector<ll>(n_dim, 0));

    MCM(p, m, s);
    print(1, n, s);

    return 0;
}