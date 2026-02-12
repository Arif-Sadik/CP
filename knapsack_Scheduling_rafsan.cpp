#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second; 
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
    int previous = 0;

    for (auto item : items)
    {
        if (item.first >= previous)
        {
            task++;
            previous = item.second;
        }
    }

    cout << task << endl;
}