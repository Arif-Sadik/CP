#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-09-04

bool canR(int n)
{
    if(n==1) return true;
    if (n%10==0)
    {
        canR(n/10);
        return true;
    }
    if (n%20==0)
    {
        canR(n/20);
        return true;
    }
    return false;
}

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
        if (canR(n))
        {
            cout<<"YES\n";

        }
        else cout<<"NO\n";
        
        
        
    }

    return 0;
}