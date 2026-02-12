#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,m,k,x, c=0, s=0, d=0, t;
    cin>>n>>m;
    map<string, int> word;
    //map<string, int> eb;
    while (n--)
    {
        string str;
        cin>>str;
        word[str]=1;
    }
    while (m--)
    {
        string str;
        cin>>str;
        if (word[str]==1)
        {
            word[str]=3;
        }
        else word[str]=2;
    }

    for (auto x: word)
    {
        if (x.second==1) c++;
        else if (x.second==2)  s++;
        else if (x.second==3)  d++;
        
    }

    ll p=c+ (d+1)/2;
    ll e=s+d/2;

    if (p>e) cout<<"YES";
    else cout<<"NO";

    

    return 0;
}