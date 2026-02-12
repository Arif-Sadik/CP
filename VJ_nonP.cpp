#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-03
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,x, c, s, d, t;
    cin>>t;
    while(t--)
    {
        c=0, s=0, d=0;
        cin>>n;
        while (n--)
        {
            cin>>d;
            if (d==0)
            {
                c=0;
                break;
            }
            if (d<0)
            {
                c++;
            }
        }
        if (c%2==0)
        {
            cout<<0<<"\n";
        }
        else cout<<1<<"\n";
        
        
    }

    return 0;
}