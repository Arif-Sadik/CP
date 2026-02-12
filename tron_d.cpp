#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-30

void merge(vector<ll> &arr, ll l, ll mid, ll r, ll &count)
{
    ll i = l;
    ll j = mid + 1;
    ll k = 0;
    vector<ll> temp(r - l + 1);
    while (i <= mid && j <= r)
    {
        if (arr[i] >= arr[j])
        {
            count += (mid - i + 1);
            temp[k++] = arr[j++];
        }
        else
        {
            temp[k++] = arr[i++];
        }
    }
    while (i <= mid)
        temp[k++] = arr[i++];
    while (j <= r)
        temp[k++] = arr[j++];

    for (ll p = 0; p < k; p++)
    {
        arr[l + p] = temp[p];
    }
}
void mergeSort(vector<ll> &arr, ll l, ll r, ll &count)
{
    if (l < r)
    {
        ll mid = l + (r - l) / 2;
        mergeSort(arr, l, mid, count);
        mergeSort(arr, mid + 1, r, count);
        merge(arr, l, mid, r, count);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        s = 0;
        cin >> n;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        mergeSort(a, 0, n - 1, s);
        cout << s << "\n";
    }

    return 0;
}