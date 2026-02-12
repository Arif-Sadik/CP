#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.second < p2.second
}

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> items;
    for (int i = 0; i < n; i++)
    {
        int start, end;
        cin >> start >> end;
        items.push_back({start, end});
    }
    sort(items.begin(), items.end(), comp);

    int task = 0;
    int prev = 0; // previous

    for (auto it : items)
    {
        if (it.first >= prev)
        {
            task++;
            prev = it.second;
        }
    }
    cout << task << "\n";
}