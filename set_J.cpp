#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int f(int x)
{
    x += 1;
    while (x % 10 == 0)
    {
        x /= 10;
    }
    return x;
}

int main()
{
    int n;
    cin >> n;

    set<int> st; 

    while (st.find(n) == st.end())
    {
        st.insert(n);
        n = f(n);
    }

    cout << st.size() << endl;
    return 0;
}
