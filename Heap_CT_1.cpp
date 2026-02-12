#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
public:
    vector<int> A;
    int heap_size;

    MaxHeap()
    {
        heap_size = 0;
    }

    // ============================
    // 1. PARENT, LEFT, RIGHT
    // ============================
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

    // ============================
    // 2. PERCOLATE DOWN (HEAPIFY)
    // Matches PDF "PercolateDown"
    // ============================
    void heapify(int i)
    {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heap_size && A[l] > A[largest])
            largest = l;

        if (r < heap_size && A[r] > A[largest])
            largest = r;

        if (largest != i)
        {
            swap(A[i], A[largest]);
            heapify(largest); // recursive call
        }
    }

    // ============================
    // 3. BUILD HEAP (O(n))
    // Matches PDF BuildHeap
    // ============================
    void buildHeap()
    {
        heap_size = A.size();
        for (int i = heap_size / 2 - 1; i >= 0; i--)
            heapify(i);
    }

    // ============================
    // 4. PERCOLATE UP
    // Matches PDF PercolateUp
    // ============================
    void percolateUp(int i)
    {
        while (i > 0 && A[parent(i)] < A[i])
        {
            swap(A[i], A[parent(i)]);
            i = parent(i);
        }
    }

    // ============================
    // 5. INSERT KEY
    // Steps in PDF:
    //  Increase heap size
    //  Put new element at end
    //  PercolateUp
    // ============================
    void insertKey(int key)
    {
        A.push_back(key);
        heap_size++;
        percolateUp(heap_size - 1);
    }

    // ============================
    // 6. INCREASE KEY
    // Matches PDF "Increase Key"
    // ============================
    void increaseKey(int i, int newKey)
    {
        if (newKey < A[i])
        {
            cout << "New key smaller than current key!\n";
            return;
        }
        A[i] = newKey;
        percolateUp(i);
    }

    // ============================
    // 7. DELETE MAX (ROOT)
    // Matches PDF DeleteMax:
    //  Save root
    //  Replace with last element
    //  Reduce size
    //  PercolateDown
    // ============================
    int deleteMax()
    {
        if (heap_size <= 0)
            return INT_MIN;

        int maxVal = A[0];
        A[0] = A[heap_size - 1];
        heap_size--;
        A.pop_back();
        heapify(0);

        return maxVal;
    }

    // ============================
    // 8. HEAP SORT
    // Matches PDF HeapSort logic
    // ============================
    vector<int> heapSort()
    {
        buildHeap();
        int originalSize = heap_size;

        for (int i = heap_size - 1; i >= 1; i--)
        {
            swap(A[0], A[i]);
            heap_size--;
            heapify(0);
        }

        heap_size = originalSize;
        return A; // A is now sorted
    }

    // ============================
    // UTILITY: PRINT
    // ============================
    void print()
    {
        cout << "Heap = ";
        for (int x : A)
            cout << x << " ";
        cout << "\n";
    }
};

int main()
{
    MaxHeap h;

    // Initial array from your PDF
    h.A = {16, 14, 10, 8, 7, 9, 3, 2, 4, 1};

    cout << "\nBuilding Heap...\n";
    h.buildHeap();
    h.print();

    cout << "\nInsert 15...\n";
    h.insertKey(15);
    h.print();

    cout << "\nIncrease A[5] to 20...\n";
    h.increaseKey(5, 20);
    h.print();

    cout << "\nDelete Max...\n";
    cout << "Deleted: " << h.deleteMax() << "\n";
    h.print();

    cout << "\nHeap Sort:\n";
    vector<int> sorted = h.heapSort();
    for (int x : sorted)
        cout << x << " ";
    cout << endl;

    return 0;
}
