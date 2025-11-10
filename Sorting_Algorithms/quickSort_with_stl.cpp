#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        auto it = partition(arr.begin() + low, arr.begin() + high + 1,
                               [pivot](int x) { return x < pivot; });
        int pivotIndex = distance(arr.begin(), it);
        swap(*it, arr[high]);
        
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> myArray = {64, 34, 25, 12, 22, 11, 90, 5};
    
    quicksort(myArray, 0, myArray.size() - 1);
    
    cout << "Sorted array: ";
    for (const auto& num : myArray) {
        cout << num << " ";
    }
    return 0;
}