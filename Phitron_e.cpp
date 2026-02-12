#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-30

const ll N = 200005;
const ll K = 19; // 2^18 > 200000

ll h[N];
ll st_first[N][K]; // Stores index of max (picks left on tie)
ll st_last[N][K];  // Stores index of max (picks right on tie)
ll lg[N];

ll bad_up[N];   // Prefix sum of bad steps for climbing
ll bad_down[N]; // Prefix sum of bad steps for descending

void build(ll n) {
    lg[1] = 0;
    for (ll i = 2; i <= n; i++) lg[i] = lg[i/2] + 1;

    for (ll i = 0; i < n; i++) {
        st_first[i][0] = i;
        st_last[i][0] = i;
    }

    for (ll j = 1; j < K; j++) {
        for (ll i = 0; i + (1 << j) <= n; i++) {
            ll right_half = i + (1 << (j - 1));

            // Logic for FIRST max (Prefer Left): >=
            ll i1 = st_first[i][j - 1];
            ll i2 = st_first[right_half][j - 1];
            st_first[i][j] = (h[i1] >= h[i2]) ? i1 : i2;

            // Logic for LAST max (Prefer Right): <= implies right is better or equal
            // Actually, simply: if right is >= left, take right
            ll j1 = st_last[i][j - 1];
            ll j2 = st_last[right_half][j - 1];
            st_last[i][j] = (h[j2] >= h[j1]) ? j2 : j1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, q;
    cin>>n>>q;

    for (ll i = 0; i < n; i++) cin >> h[i];

    build(n);
    for (ll i = 0; i < n - 1; i++) {
        bad_up[i + 1] = bad_up[i] + (h[i] > h[i + 1]);    
        bad_down[i + 1] = bad_down[i] + (h[i] < h[i + 1]); 
    }

    while (q--) {
        ll l, r;
        cin >> l >> r;
        l--; r--; 

        ll j = lg[r - l + 1];
        ll right_half = r - (1 << j) + 1;

        ll i1 = st_first[l][j];
        ll i2 = st_first[right_half][j];
        ll first_idx = (h[i1] >= h[i2]) ? i1 : i2;

        ll j1 = st_last[l][j];
        ll j2 = st_last[right_half][j];
        ll last_idx = (h[j2] >= h[j1]) ? j2 : j1;

        if (first_idx != last_idx) {
            cout << "NO\n";
        } 
        else {
            ll m = first_idx;
            
            bool climb_ok = (bad_up[m] - bad_up[l] == 0);

            bool descent_ok = (bad_down[r] - bad_down[m] == 0);

            if (climb_ok && descent_ok) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
}