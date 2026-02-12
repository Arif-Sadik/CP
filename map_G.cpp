#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    ll n,q,k,x, c, s, d, t;
    cin>>n>>q;
    map<ll,ll> mp;
    while (q--)
    {
        ll x, y;
        cin>>x>>y;
        if (x==1)
        {
            mp[y]=-1;
        }
        else if (x==2)
        {
            auto it=mp.lower_bound(y);
            if (it!=mp.end()&& (*it).second==-1)
            {
                cout<<(*it).first<<"\n";
            }
            else cout<<-1<<"\n";
        }

        
    }
    
    

    return 0;
}