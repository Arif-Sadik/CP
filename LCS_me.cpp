#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2026-04-06

ll lcs(string s1, string s2)
{
    ll n= s1.size();
    ll m= s2.size();
    vector<vector<ll>>dp(n+1,vector<ll>(m+1,0));
    for(ll i = 0; i < n; i++) {
        dp[i][0]=0;
    }
    for(ll i = 0; i < m; i++) {
        dp[0][i]=0;
    }

    for(ll i = 1; i <= n; i++) {
        for(ll j = 1; j <=m; j++) {
            if (s1[i-1]==s2[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else {
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    return dp[n][m];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s1,s2;
    cin>>s1>>s2;
    cout<<lcs(s1,s2);

    return 0;
}