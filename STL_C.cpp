#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,k,x, c, s, d, t;
    cin>>t;
    while(t--)
    {
        c=0, s=0, d=0;
        string str;
        cin>>n>>str;
        for(ll i = 0; i < n-2; i++) {
            if (str.substr(i,3)=="pie"||str.substr(i,3)=="map")
            {
                c++;
                i+=2;
            }
        }
        cout<<c<<endl;
        
        
    }

    return 0;
}