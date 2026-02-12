#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n;
    cin >> n;

    if (n == 0) {
        cout << 1 << "\n"; 
    } else {
        int cycle[] = {8, 4, 2, 6};
        cout << cycle[(n - 1) % 4] << "\n";
    }

    return 0;
}
