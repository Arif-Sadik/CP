#include <bits/stdc++.h>
using namespace std;

// partition using k-th pivot (0-based index)
int partition(vector<int> &a, int low, int high, int k)
{
    swap(a[k], a[high]);  // move pivot to end
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
    cout << "Pivot " << pivot << " is at index " << i + 1 << endl; // print pivot position

    return i + 1;
}

// quick sort with k-th pivot
void quick_sort(vector<int> &a, int low, int high, int k)
{
    if (low < high)
    {
        int p = partition(a, low, high, k);
        // next recursive calls can choose any pivot, here just first element for simplicity
        quick_sort(a, low, p - 1, low);  
        quick_sort(a, p + 1, high, low); 
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;  // k = 1-based index of pivot
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    quick_sort(a, 0, n - 1, k - 1);  // convert to 0-based

    for (int x : a) cout << x << " ";
    return 0;
}
