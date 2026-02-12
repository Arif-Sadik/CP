#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,m,k,x, c, s, d, t;
    cin>>n>>m;
    map<string,string> mp;
    while(n--)
    {
        string a1,a2;
        cin>>a1>>a2;
        mp[a2]=a1;
    }
    while(m--)
    {
        string a1,a2;
        cin>>a1>>a2;
        a2.pop_back();
        cout<<a1<<" "<<a2<<"; #"<<mp[a2]<<endl;
    }

    return 0;
}