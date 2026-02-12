#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n, k, x, c, s, d, t;
    cin >> t;
    map<string, vector<ll>> mark;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> n;
        if (n == 0)
        {
            string a;
            cin >> a >> x;
            mark[a].push_back(x);
        }
        else if (n == 1)
        {
            string a;
            cin >> a;
            for (auto val : mark[a])
            {
                cout << val << endl;
            }
        }
        else if (n == 2)
        {
            string a;
            cin >> a;
            mark.erase(a);
        }
        else if (n == 3)
        {
            string L, R;
            cin >> L >> R;

            for (auto it = mark.lower_bound(L); it != mark.upper_bound(R); it++)
            {
                for (auto val : (*it).second)
                {
                    cout << (*it).first << " " << val << endl;
                }
            }
        }
    }

    return 0;
}