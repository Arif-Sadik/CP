#include <iostream>
using namespace std;

class DynamicArray {
    int* arr;
    int size;
    int capacity;

public:
    DynamicArray(int cap) {
        capacity = cap;
        size = 0;
        arr = new int[capacity];
    }

    DynamicArray(const DynamicArray& other) {
        capacity = other.capacity;
        size = other.size;
        arr = new int[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = other.arr[i];
        }
    }

    ~DynamicArray() {
        delete[] arr;
    }

    void addElement(int element) {
        if (size < capacity) {
            arr[size++] = element;
        } else {
            cout << "Array is full!" << endl;
        }
    }

    void removeElement() {
        if (size > 0) {
            size--;
        } else {
            cout << "Array is empty!" << endl;
        }
    }

    void printArray() {
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int getSum() {
        int sum = 0;
        for (int i = 0; i < size; i++) {
            sum += arr[i];
        }
        return sum;
    }
};

int main() {
    DynamicArray arr1(5);
    arr1.addElement(10);
    arr1.addElement(20);
    arr1.addElement(30);

    arr1.printArray();
    cout << "Sum of elements: " << arr1.getSum() << endl;

    DynamicArray arr2 = arr1;

    arr2.printArray();
    cout << "Sum of elements in copied array: " << arr2.getSum() << endl;

    arr2.removeElement();
    arr2.printArray();

    return 0;
}
