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
        cin>>n;
        ll arr[n];
        for(ll i = 0; i < n; i++) {
            cin>>arr[i];
            s+=arr[i];
        }
        if (s==0||s>=n)
        {
             cout<<"Yes"<<endl;
        }
        else
        {
            for(ll i = 0; i < n-1; i++) {
                if (arr[i]==0&&arr[i+1]==0)
                {
                    c=1;
                    break;
                }
            }
            if (c==1)  cout<<"Yes"<<endl;
            else cout<<"NO"<<endl;
        }
        
    }

    return 0;
}