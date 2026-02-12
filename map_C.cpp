#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n, k, x, c, s, d, t;
    cin >> t;
    map<string, ll> mark;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> n;
        if (n == 0)
        {
            string a;
            cin >> a >> x;
            mark[a] = x;
        }
        else if (n == 1)
        {
            string a;
            cin >> a;
            cout << mark[a] << endl;
        }
        else if (n == 2)
        {
            string a;
            cin>>a;
            mark.erase(a);
        }
    }

    return 0;
}