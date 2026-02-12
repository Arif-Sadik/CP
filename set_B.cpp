#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n, k, x, c, s, d, t;
    cin >> t;
    set<ll> st;
    while (t--)
    {
        cin >> n;
        if (n == 0)
        {
            cin >> x;
            st.insert(x);
            cout << st.size() << "\n";
        }
        else if (n == 1)
        {
            cin >> x;
            cout << (st.count(x) ? 1 : 0) << "\n";
        }
        else if (n == 2)
        {
            cin >> x;
            st.erase(x);
        }
        else if (n==3)
        {
            ll l,r;
            cin>>l>>r;
            auto it=st.lower_bound(l);
            while(it!=st.end() && *it<=r)
            {
                cout<<*it;
                cout<<"\n";
                it++;
            }
        }
    }

    return 0;
}