#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-10-10

bool prime(int n)
{
    int div = 0;
    for (int j = 1; j <= n; j++)
    {
        if (n % j == 0)
        {
            div++;
        }
    }
    if (div == 2)
    {
        return true;
    }
    else
        return false;
}

bool almost_p(int n)
{
    int prime_div = 0;
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            if (prime(i))
            {
                prime_div++;
            }
        }
    }
    if (prime_div == 2)
    {
        return true;
    }
    else
        return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, k, x, c, s = 0, d, t;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        if (almost_p(i))
        {
            s++;
        }
    }
    cout << s << '\n';

    return 0;
}