#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-21

vector<ll> vc;
vector<ll> merge(vector<ll> &l, vector<ll> &r)
{
    ll n = l.size();
    ll m = r.size();
    vector<ll> ans;
    ll i = 0;
    ll j = 0;
    while (i < n && j < m)
    {
        if (l[i] < r[j])
        {
            ans.push_back(l[i++]);
        }
        else
            ans.push_back(r[j++]);
    }
    while (i < n)
    {
        ans.push_back(l[i++]);
    }
    while (j < m)
    {
        ans.push_back(r[j++]);
    }
    return ans;
}

vector<ll> merge_sort(ll l, ll r)
{
    if (l == r)
    {
        return {vc[l]}; /// must notice
    }
    ll mid = (l + r) >> 1;
    vector<ll> left = merge_sort(l, mid);
    vector<ll> right = merge_sort(mid + 1, r);

    return merge(left, right);
}

int main()
{
    ll n;
    cin >> n;
    vc.resize(n); // must notice
    for (ll i = 0; i < n; i++)
    {
        cin >> vc[i];
    }
    vector<ll> ans = merge_sort(0, n - 1); // must store this here
    for (ll i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}