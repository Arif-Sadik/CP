
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define str string

int main(){

    ll t;
    cin>>t;
    while(t--){
        ll n,m,p,q;
        cin>>n>>m>>p>>q;
        if (n%p==0)
        {
            if (m==n*q/p) cout<<"YES"<<endl;
            else cout<<"NO"<<endl;
        }
        else cout<<"YES"<<endl;

    }

}
