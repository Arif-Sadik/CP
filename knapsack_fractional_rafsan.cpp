#include <bits/stdc++.h>

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b)
{
    float upa = (float)a.second / a.first;
    float upb = (float)b.second / b.first;
    return upa > upb;
}

int main()
{

    int weight;
    cin >> weight;
    int n;
    cin >> n;

    vector<pair<int, int>> items;

    for (int i = 0; i < n; i++)
    {
        int w, p;
        cin >> w >> p;

        items.push_back({w, p});
    }
    sort(items.begin(), items.end(), comp);

    int profit = 0;
    for (auto item : items)
    {

        int w = item.first;
        int p = item.second;

        if (w <= weight)
        {
            profit += p;
            weight -= w;
        }
        else if (w > weight)
        {
            profit += ((float)weight / w) * p;
            break;
        }
    }
    cout << profit << endl;
}