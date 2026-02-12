#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ll t;
    cin >> t;
    while(t--) {
        ll n, sum = 0;
        cin >> n;
        ll arr[n];
        for(ll i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
        }

        // Invalid if everyone claims they won or no one does
        if (sum >= n || sum == 0) {
            cout << "YES" << endl;  // Someone is lying
        } else {
            cout << "NO" << endl;   // Reports can be valid
        }
    }
    return 0;
}
