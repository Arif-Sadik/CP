#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    long double n,m,k,x, c, s, d, t;
    cin>>t;
    while(t--)
    {
        c=0, s=0, d=0;
        double a,b;
        cin>>n>>m>>k;
        //x=ceil(sqrt(k));
        if (k==0)
        cout<<n*m<<endl;
        else 
        {
        a=(k/n), b=(k/m);
        a=ceil(a)*n;
        b=ceil(b)*m;
        if (a<=b)
        {
            cout<<n*m-a<<endl;
        }
        else cout<<n*m-b<<endl;
        }

        
    }

    return 0;
}