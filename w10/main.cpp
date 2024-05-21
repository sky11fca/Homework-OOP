#include "Arr.h"

using namespace std;

// Custom comparison function
int compareInts(const int& a, const int& b) {
    return a - b;
}

// Custom comparator class
class IntCompare : public Compare {
public:
    int CompareElements(void* e1, void* e2) override {
        int* int1 = static_cast<int*>(e1);
        int* int2 = static_cast<int*>(e2);
        return *int1 - *int2;
    }
};

int main() {
    try {
        // Create an Array with a capacity of 10
        Array<int> arr(10);

        // Add elements to the array
        arr += 5;
        arr += 3;
        arr += 8;
        arr += 1;

        cout << "Initial array:" << endl;
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Sort the array using the default comparison operator
        arr.Sort();
        cout << "Sorted array:" << endl;
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Perform binary search for an element
        int index = arr.BinarySearch(3);
        if (index != -1) {
            cout << "Element 3 found at index " << index << endl;
        } else {
            cout << "Element 3 not found" << endl;
        }

        // Insert element at a specific index
        arr.Insert(2, 6);
        cout << "Array after inserting 6 at index 2:" << endl;
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Delete an element from the array
        arr.Delete(1);
        cout << "Array after deleting element at index 1:" << endl;
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Sort the array using a custom comparison function
        arr.Sort(compareInts);
        cout << "Array sorted with custom comparison function:" << endl;
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Create an instance of the custom comparator class
        IntCompare comparator;

        // Sort the array using the custom comparator class
        arr.Sort(&comparator);
        cout << "Array sorted with custom comparator class:" << endl;
        for (int i = 0; i < arr.GetSize(); i++) {
            cout << arr[i] << " ";
        }
        cout << endl;

        // Perform a linear search
        int findIndex = arr.Find(8);
        if (findIndex != -1) {
            cout << "Element 8 found at index " << findIndex << endl;
        } else {
            cout << "Element 8 not found" << endl;
        }

    } catch (exception& e) {
        cout << "Exception: " << e.what() << endl;
    }

    return 0;
}