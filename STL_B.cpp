#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,k, c, s, d, t;
    cin>>t;
    while(t--)
    {
        bool x=false;
        string str;
        cin>>str;
        n=str.length();
        for(ll i = 0; i < n-1; i++) {
            if (str[i]==str[i+1])
            {
                x=true;
                break;
            }
        }
        if (x) cout<<1<<endl;
        else cout<<n<<endl;
        
        
    }

    return 0;
}