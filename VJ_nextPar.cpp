#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-02-06
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,x, c, s, d, t;
    c=0;
    cin>>n;
    while (n>0)
    {
        if (n%2==1)
        c++;
        n/=2;
    }
    cout<<c<<endl;


    return 0;
}