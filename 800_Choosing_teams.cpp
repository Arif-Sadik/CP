#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,k,x, c, s, d, t;
    
        c=0, s=0, d=0;
        cin>>n>>k;
        d=5-k;
        vector<ll> arr(n);
        for(ll i = 0; i < n; i++) 
        {
            cin>>arr[i];
            if (arr[i]<=d)  c++;
        }

        cout<<c/3<<endl;
        
    

    return 0;
}