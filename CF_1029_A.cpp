#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n >> x;
        vector<ll> a(n);
        for (ll i = 0; i < n; i++) cin >> a[i];

        ll left = -1, right = -1;

        for (ll i = 0; i < n; i++) {
            if (a[i]) {
                if (left == -1) left = i;
                right = i;
            }
        }

        if (right - left + 1 <= x) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }
    return 0;
}
