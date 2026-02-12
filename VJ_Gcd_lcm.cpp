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
    ll t=1, a,b,g,l;
    //cin>>t;
    while(t--)
    {
        cin>>g>>l;
        
        cout<<g*l/__gcd(g,l)<<endl;
        
        
    }

    return 0;
}