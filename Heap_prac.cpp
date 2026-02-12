#include <bits/stdc++.h>
#define ll long long
#define dubb long double
#define pi acos(-1)
using namespace std;

// Md. Arif Sadik Molla
// Date: 2025-12-21

class MaxHeap
{
public:
    vector<ll> vc;
    ll heap_size;
    MaxHeap()
    {
        heap_size = 0;
    }

    int parent(int i) // par left right
    {
        return (i - 1) / 2;
    }
    int left(int i)
    {
        return (i * 2 + 1);
    }
    int right(int i)
    {
        return (i * 2 + 2);
    }

    void heapify(int i) // Parcolate down
    {
        ll l = left(i);
        ll r = right(i);
        ll largest = i;
        if (l < heap_size && vc[l] > vc[largest])
        {
            largest = l;
        }
        if (r < heap_size && vc[r] > vc[largest])
        {
            largest = r;
        }
        if (largest != i)
        {
            swap(vc[largest], vc[i]);
            heapify(largest); // Recursive call
        }
    }

    void build_heap() // Build Heap of vector
    {
        heap_size = vc.size();
        for (ll i = heap_size / 2 - 1; i >= 0; i--)
        {
            heapify(i);
        }
    }

    void parcolate_up(int i) // Parcolate Up
    {
        while (i > 0 && vc[i] > vc[parent(i)])
        {
            swap(vc[i], vc[parent(i)]);
            i = parent(i);
        }
    }

    void insert(int x) // Insert
    {
        vc.push_back(x);
        heap_size++;
        parcolate_up(heap_size - 1);
    }

    void increase(int i, int key) // Increase
    {
        vc[i] = key;
        parcolate_up(i);
    }

    int delMax() // Delete Max
    {
        if (heap_size <= 0)
        {
            return INT_MIN;
        }
        int maxVal = vc[0];
        vc[0] = vc[heap_size - 1];
        heap_size--;
        heapify(0);
        return maxVal;
    }

    vector<ll> heapSort() // Heap Sort
    {
        build_heap();
        ll a_size = heap_size;
        for (ll i = heap_size - 1; i > 0; i--)
        {
            swap(vc[0], vc[i]);
            heap_size--;
            heapify(0);
        }
        heap_size = a_size;
        return vc;
    }

    void print() // Print
    {
        for (int x : vc)
        {
            cout << x << " ";
        }
        cout << endl;
    }
};

int main()
{

    MaxHeap m;
    m.vc = {23, 22, 67, 33, 89, 346, 222, 90, 76};
    m.print();

    m.build_heap();
    m.print();

    m.heapSort();
    m.print();

    m.insert(999);
    m.print();
    m.heapSort();
    m.print();

    return 0;
}