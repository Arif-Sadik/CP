#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,k,x,y, c, s, d, t;
    cin>>t;
    while(t--)
    {
        c=0, s=0, d=0;
        bool bob=true;
        cin>>x>>y>>k;
        for(ll i = 1; i <= k; i++) {
            if (y>=i)
            {
                ll b=y-i;
                if (x<=i&&b<=i)
                {
                    bob=false;
                    break;
                }
            }
            if (x>=i)
            {
                ll a=x-i;
                if (a<=i&&y<=i)
                {
                    bob=false;
                    break;
                }
            }
        }
        if (bob)
        {
            cout<<"Bob"<<endl;
        }
        else cout<<"Alice"<<endl;
        
        
    }

    return 0;
}