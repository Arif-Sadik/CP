#include <bits/stdc++.h>
using namespace std;

bool comp(pair<int, int> p1, pair<int, int> p2)
{
    float up1 = float(p1.second / p1.first);
    // Unit price
    float up2 = float(p2.second / p2.first);

    return up1 > up2;
}

int main()
{
    int wt; // highest wt
    cin >> wt;
    int n;
    cin >> n;
    vector<pair<int, int>> items;
    for (int i = 0; i < n; i++)
    {
        int w, p; // wt,price
        cin >> w >> p;
        items.push_back({w, p});
    }
    sort(items.begin(), items.end(), comp);

    int profit = 0; // result

    for (auto it : items)
    {
        int w = it.first;
        int p = it.second;

        if (w <= wt)
        {
            wt -= w;
            profit += p;
        }
        else if (w > wt)
        {
            profit += float(w / wt) * p;
            break;
        }
    }

    cout << profit << endl;
}
