#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-10
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,x, c, s, d, t;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        if (k/n<2)
        {
            cout<<"-1 -1"<<endl;
        }
        else {
            cout<<n<<" "<<2*n<<endl;
        }
        
        
    }

    return 0;
}