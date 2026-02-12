#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-09-08
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t;
    cin >> t;
    while(t--)
    {
        ll a, b;
        cin >> a >> b;

        if(a == b) {
            cout << 0 << "\n";
        }
        else if(max(a, b) % min(a, b) == 0) {
            cout << 1 << "\n";
        }
        else {
            cout << 2 << "\n";
        }
    }

    return 0;
}
