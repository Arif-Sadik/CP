#include<bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

int main()
{
    ll n,k,x, c, s, d, t;
    cin>>t;
    map<string, int> marks;
    while(t--)
    {
        int type;
        string name;
        cin >> type >> name;

        if (type == 1) {
            int score;
            cin >> score;
            marks[name] += score;
        } else if (type == 2) {
            marks.erase(name);
        } else if (type == 3) {
            cout << marks[name] << endl;
        }
        
        
    }

    return 0;
}