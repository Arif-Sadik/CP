#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    string ab;
    bool x=true;
    cin>>ab;
    for(ll i = 0; i < ab.size(); i++) {
        if (ab[i]=='H'||ab[i]=='Q'||ab[i]=='9'){
        cout<<"YES";
        x=false;
        break;
        }
    }
    if (x==true) cout<<"NO";

    return 0;
}