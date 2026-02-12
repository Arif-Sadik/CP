#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,k,x, c=0, s=0, d=0, t;
    cin>>n;
    ll arr[n];
    for(ll i = 0; i < n; i++) {
        cin>>arr[i];
    }
    for(ll i = 0; i < n-1; i++) {
        if (arr[i]<=arr[i+1])
        {
            c++;
            if (c>s)
            s=c;
        }
        else c=0;

    }
    cout<<s+1;


    return 0;
}