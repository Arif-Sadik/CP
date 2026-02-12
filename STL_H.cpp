#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,m,k,x, c=0, s, d, t;
    cin>>n>>m;
    vector<ll> arr(n);
    for(ll i = 0; i < n; i++) {
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
    for(ll i = 0; i < m; i++) {
        if (arr[i]<=0)
        {
            c+=arr[i];
        }    
        else break;   

        
        
    }
    
    cout<<(-c)<<endl;


    return 0;
}