#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-09-30
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,x, c, s, d, t,a,b;
    cin>>t;
    while(t--)
    {
        cin>>a>>b>>c;
        ll na=2*b-c;
        if (na%a==0&&na!=0&&na>=a)
        {
            cout<<"Yes\n";
            continue;
        }
        ll nb=(a+c)/2;
        if (nb%b==0&&nb>=b&&nb!=0&&(c-a)%2==0)
        {
            cout<<"Yes\n";
            continue;
        }
        ll nc= 2*b-a;
        if (nc%c==0&&nc>=c&&nc!=0)
        {
            cout<<"Yes\n";
            continue;

        }




        cout<<"No\n";
        
        
    }

    return 0;
}