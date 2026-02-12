#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-10
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,m,k,x, c=0, s, d=1, t;
    cin>>n>>m;

    while (d<=m)
    {
        d<<=1;
        c++;
    }
    if (n>c)
    {
        cout<<m<<endl;
        return 0;
    }
    x=1<<n;
    cout<<m%x<<endl;
    

    return 0;
}