#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        ll xl, yl, xr, yr;
        ll x1, y1, x2, y2;
        cin >> xl >> yl >> xr >> yr;
        cin >> x1 >> y1 >> x2 >> y2;
        ll xmin = min(xl, xr), xmax = max(xl, xr);
        ll ymin = min(yl, yr), ymax = max(yl, yr);
        bool left = (x1 < xmin && x2 < xmin);
        bool right = (x1 > xmax && x2 > xmax);
        bool down = (y1 < ymin && y2 < ymin);
        bool up = (y1 > ymax && y2 > ymax);

        if (left || right || down || up)
            cout << "OK\n";
        else
            cout << "STOP\n";
    }

    return 0;
}
