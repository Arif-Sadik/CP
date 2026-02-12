#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        string st;
        cin >> st;

        map<char, int> freq;
        for (char ch : st)
        {
            freq[ch]++;
        }

        bool pos = false;
        for (ll i = 1; i <= n - 2; i++)
        {
            if (freq[st[i]] >= 2)
            {
                pos = true;
                break;
            }
        }
        if (pos == true)
        {
            cout << "Yes" << endl;
        }
        else
            cout << "No" << endl;
    }

    return 0;
}
