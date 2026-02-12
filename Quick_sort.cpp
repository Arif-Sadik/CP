#include <bits/stdc++.h>
using namespace std;

// partition using last element as pivot
int partition(vector<int> &a, int low, int high)
{
    int pivot = a[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
    {
        if (a[j] <= pivot)
        {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    return i + 1;
}

// quick sort on range [low, high]
void quick_sort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quick_sort(a, low, p - 1);
        quick_sort(a, p + 1, high);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    quick_sort(a, 0, n - 1);

    for (int x : a)
        cout << x << " ";

    return 0;
}
