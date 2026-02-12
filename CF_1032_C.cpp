#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n, m, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        cin >> n >> m;
        ll arr[n][m];
        ll mx = 0;
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                cin >> arr[i][j];
                mx = max(mx, arr[i][j]);
            }
        }
        ll row[n], col[m];
        for (ll i = 0; i < n; i++)
        {
            row[i] = 0;
        }
        for (ll i = 0; i < m; i++)
        {
            col[i] = 0;
        }
        for (ll i = 0; i < n; i++)
        {
            for (ll j = 0; j < m; j++)
            {
                if (arr[i][j]==mx)
                {
                    row[i]++;
                    col[j]++;
               }
            }
        }
        for(ll i = 0; i < n; i++) {
            if (row[i]>=1)
            c++;
        }
        for(ll i = 0; i < m; i++) {
            if (col[i]>=1)
            s++;
        }

        if (c>=2||s>=2)
        cout<<mx<<endl;
        else cout<<mx-1<<endl;
    }

    return 0;
}