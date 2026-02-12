#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-07
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,x, c, s, d, t;
    cin>>t;
    while(t--)
    {
        cin >> n >> k;
        vector<ll> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];

        // Sort and remove duplicates to perform binary search lookups
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        
        // Update n to the number of unique elements
        n = a.size();

        // 'keep' array will determine if an element stays in set B
        vector<bool> keep(n, true);
        bool possible = true;

        for(int i = 0; i < n; i++) {
            ll val = a[i];

            // Optimization: If the number of multiples of val exceeds the
            // total number of elements available, val cannot be valid.
            // There are floor(k/val) multiples of val <= k.
            if(k / val > n) {
                possible = false;
                break;
            }

            // Check all multiples of val: val, 2*val, 3*val ... <= k
            for(ll m = val; m <= k; m += val) {
                // Use lower_bound to find if multiple 'm' exists in 'a'
                auto it = lower_bound(a.begin(), a.end(), m);
                
                // Condition 2 Check: If a multiple is missing, no solution exists
                if(it == a.end() || *it != m) {
                    possible = false;
                    break;
                }

                // Condition 1 Logic: If m is a proper multiple (m > val), 
                // then 'val' covers 'm'. We don't need 'm' in set B.
                if(m > val) {
                    int idx = it - a.begin();
                    keep[idx] = false;
                }
            }
            if(!possible) break;
        }

        if(!possible) {
            cout << -1 << "\n";
        } else {
            vector<ll> b;
            for(int i = 0; i < n; i++) {
                if(keep[i]) {
                    b.push_back(a[i]);
                }
            }

            cout << b.size() << "\n";
            for(int i = 0; i < b.size(); i++) {
                cout << b[i] << (i == b.size() - 1 ? "" : " ");
            }
            cout << "\n";
        }
    }

    return 0;
}