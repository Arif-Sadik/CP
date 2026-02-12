#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,j,k,x, c, s, d, t;
    cin>>t;
    while(t--)
    {
        cin>>n>>j>>k;
        vector<ll> vc(n);
        for(ll i = 0; i < n; i++) {
            cin>>vc[i];
        }
        if (k>1)
        {
            cout<<"Yes"<<endl;
        }
        else{
            ll max_e=*max_element(vc.begin(), vc.end());
            if (vc[j-1]==max_e)
            {
                cout<<"YeS"<<endl;

            }
            else cout<<"NO"<<endl;
        }
        
        
    }

    return 0;
}