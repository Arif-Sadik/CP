#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll t;
    long double n,x;
    cin>>t;
    while(t--)
    {
        cin>>n;
        x=sqrt(n);
        if(x!=floor(x))
        {
            cout<<-1<<endl;
        }
        else {
            ll z=sqrt(n);
            
            cout<<z/2<<" "<<z-z/2<<endl;
        }

        
        
    }

    return 0;
}