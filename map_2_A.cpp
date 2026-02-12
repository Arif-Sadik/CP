#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,k,x, c=0, s, d, t;
    cin>>t;
    map<string,int> mp;
    while(t--)
    {
        string a;
        cin>>a;
        if (mp.find(a)==mp.end())
        {
            cout<<"OK"<<"\n";
            mp[a]=0;
        }
        else {
            mp[a]++;
            cout<<a<<mp[a]<<"\n";
        }

        
        
    }

    return 0;
}