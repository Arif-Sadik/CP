#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,k,x, c, s, d, t;
    cin>>n>>k;
    if (n%2!=0) d=n/2+1;
    else d=n/2;
    if (k<=d) cout<<2*k-1<<endl;
    else cout<<(k-d)*2<<endl;

    return 0;
}