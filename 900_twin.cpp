#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,x=0, c=0, s=0;
    cin>>n;
    vector<ll>vec(n);
    for(ll i = 0; i < n; i++) {
        cin>>vec[i];
        s+=vec[i];
    }
    sort(vec.begin(), vec.end());
    for(ll i = n-1; i >=0; i--) {
        s-=vec[i];
        x+=vec[i];
        c++;
        if (x>s) {
            cout<<c<<"\n";
            break;
        }

    }

    return 0;
}