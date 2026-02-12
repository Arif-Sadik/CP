#include <iostream>
#include <vector>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int &x : a) cin >> x;

    vector<int> leftMin(n), rightMax(n);
    leftMin[0] = a[0];
    for (int i = 1; i < n; i++)
        leftMin[i] = min(leftMin[i - 1], a[i]);

    rightMax[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        rightMax[i] = max(rightMax[i + 1], a[i]);

    for (int i = 0; i < n; i++) {
        bool leftOK = (i == 0) || (a[i] < leftMin[i - 1]);
        bool rightOK = (i == n - 1) || (a[i] > rightMax[i + 1]);
        cout << (leftOK || rightOK ? '1' : '0');
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
