#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

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
        ll arr[n];
        for(ll i = 0; i < n; i++) {
            cin>>arr[i];
        }
        x=-1;
        for(ll i = 0; i < n; i++) {
            if (arr[i]>x+1)
            {
                c++;
                x=arr[i];
            }
            //else x=arr[i-1];
        }
        cout<<c<<"\n";
        
        
    }

    return 0;
}