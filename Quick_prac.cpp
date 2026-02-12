#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-22

int part(vector<ll> &a, ll l, ll h, ll k)
{
    swap(a[k], a[h]);
    ll pivot = a[h];
    ll i = l - 1;

    for (ll j = l; j < h; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[h]);
    cout << "pivot pos " << i + 1 << endl;
    return i + 1;
}

void quick_sort(vector<ll> &a, ll l, ll r, ll k)
{
    if (l < r)
    {
        ll p = part(a, l, r, k);
        quick_sort(a, l, p - 1, l);
        quick_sort(a, p + 1, r, l);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k; // k = 1-based index of pivot
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quick_sort(a, 0, n - 1, k - 1); // convert to 0-based

    for (ll x : a)
        cout << x << " ";
    return 0;
}