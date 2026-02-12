 #include<bits/stdc++.h>
 #define ll long long
 #define dubb long double
 #define pi acos(-1)
 using namespace std;
 
 int main()
 {
     ll n,m,k,x, c, s, d, t;
     cin>>n>>m;
    map<string, string> mp;
     while(m--)
     {
        string a,b;
        cin>>a>>b;
        if (a.length()>b.length())
        {
            mp[a]=b;
        }
        else mp[a]=a;

     }
     while (n--)
     {
        string ab;
        cin>>ab;
        cout<<mp[ab]<<"\n";

     }
 
     return 0;
 }