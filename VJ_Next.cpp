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
    ll n=1;
    ll a,b,c;
    while (n)
    {
        cin>>a>>b>>c;
        if (a==0&&b==0&&c==0)
        {
            n=0;
        }
        else if ((b-a)==(c-b))
        {
            cout<<"AP "<<2*c-b;
        }
        else {
            cout<<"GP "<<c*c/b;
        }
        cout<<endl;

    }

    return 0;
}