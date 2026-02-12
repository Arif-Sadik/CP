#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-08-26
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,x, c, s, d, t,a,b;
    cin>>t;
    while(t--)
    {
        c=0, s=0, d=0;

        cin>>n>>a>>b;

        if (n%2==0&&b%2==0)
        {
            if (a%2==0||a<b)
            {
                cout<<"YES\n";
            }
            else cout<<"NO\n";

        }
        else if (n%2!=0&&b%2!=0)
        {
            if (a%2!=0||a<b)
            cout<<"YES\n";
            else cout<<"NO\n";
        }
        else cout<<"NO\n";
        
        
    }

    return 0;
}