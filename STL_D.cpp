#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n, k, x, c, s, d, t;
    cin >> t;
    while (t--)
    {
        c = 0, s = 0, d = 0;
        string str, final;
        cin >> str;
        for (char ch : str)
        {
            if (ch == 'b')
            {
                for (int i = final.length() - 1; i >= 0; i--)
                {
                    if (islower(final[i]))
                    {
                        final[i]='2';
                       // final.erase(i, 1);
                        break;
                    }
                }
            }
            else if (ch == 'B')
            {
                for (int i = final.length() - 1; i >= 0; i--)
                {
                    if (isupper(final[i]))
                    {
                        final[i]='2';
                      //  final.erase(i, 1);
                        break;
                    }
                }
            }
            else
                final.push_back(ch);
        }
       
        string f2;
        for (char ch: final)
        {
            if (ch!='2')
            {
                f2.push_back(ch);
            }
        }
       
       
        cout << f2 << "\n";
    }

    return 0;
}