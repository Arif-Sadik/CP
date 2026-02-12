#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    if (!(cin >> t)) return 0;
    while (t--) {
        unsigned int n;
        cin >> n;

        bool ok = false;
        for (int L = 1; L <= 30; ++L) {
            if (n >= (1u << L)) continue;   // n must fit in L bits

            bool pal = true;
            int half = L / 2;               // number of pairs to check
            for (int i = 0; i < half; ++i) {
                int bi = (n >> i) & 1u;
                int bj = (n >> (L - 1 - i)) & 1u;
                if (bi != bj) { pal = false; break; }
            }
            if (!pal) continue;

            // If L is odd, middle bit must be 0
            if ((L & 1) && (((n >> (L / 2)) & 1u) != 0)) continue;

            ok = true;
            break;
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}
