#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-11-25
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n,k,x, c,  d, t;
    string l1="qwertyuiop";
    string l2="asdfghjkl;";
    string l3="zxcvbnm,./";
    char ch;
     cin>>ch;
     string s;
     cin>>s;
     if (ch=='R')
     {
        for(ll i = 0; i < s.size(); i++) {
            for(ll j = 0; j < 10; j++) {
                if (s[i]==l1[j])
                {
                    s[i]=l1[j-1];
                    break;
                }
                else if (s[i]==l2[j])
                {
                    s[i]=l2[j-1];
                    break;
                }
                else if(s[i]==l3[j])
                {
                    s[i]=l3[j-1];
                    break;
                }
            }
        }
     }
     else if (ch=='L')
     {
        for(ll i = 0; i < s.size(); i++) {
            for(ll j = 0; j < 10; j++) {
                if (s[i]==l1[j])
                {
                    s[i]=l1[j+1];
                    break;
                }
                else if (s[i]==l2[j])
                {
                    s[i]=l2[j+1];
                    break;
                }
                else if(s[i]==l3[j])
                {
                    s[i]=l3[j+1];
                    break;
                }
            }
        }
     }
     cout<<s<<endl;

    return 0;
}
