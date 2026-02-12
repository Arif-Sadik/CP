
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n;
        cin>>n;
        vector<ll> arr(n);
        for(ll i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        ll a1=abs(arr[0]);
        //sort(arr.begin(), arr.end());
        ll c=0;   //less count
        for (ll i=1; i<n; i++)
        {
            if (a1>abs(arr[i]))     c++;
        }
        if (c>n/2)   cout<<"No"<<endl;
        else cout<<"Yes"<<endl;
    }
    return 0;

}
