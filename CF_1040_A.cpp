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
        vector<ll>set(n);
        for(ll i = 0; i < n; i++) {
            cin>>set[i];
        }

        vector<ll> freq(51,0);
        for(ll i = 0; i < n; i++) {
            freq[set[i]]++;
        }

        c=min(freq[0], freq[1]);
        //s=freq[0]+freq[1];
        
        freq[0]-=c;
        freq[1]-=c;
        s=c*2+freq[0];
        freq[0]=0;

        for(ll i = 0; i < 51; i++) {
            if (freq[i]>0)
            {
                s+=freq[i]*i;
            }
        }

        cout<<s<<"\n";




        
        
    }

    return 0;
}