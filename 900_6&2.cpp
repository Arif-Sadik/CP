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
        while (n%2==0)
        {
            n/=2;
            c++;
        }
        while(n%3==0)
        {
            n/=3;
            s++;
        }
        if (n==1&&c<=s)
        {
            cout<<2*s-c<<endl;
            
        }
        else cout<<-1<<endl;
        
        
    }

    return 0;
}