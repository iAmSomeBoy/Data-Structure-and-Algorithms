#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            // Swap elements
            swap(arr[i], arr[j]);
        }
    }

    // Swap pivot to correct position
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main() {
    vector<int> myArray = {64, 34, 25, 12, 22, 11, 90, 5};
    
    quicksort(myArray, 0, myArray.size() - 1);
    
    cout << "Sorted array: ";
    for(auto x: myArray){
        cout<<x<<" ";
    } cout<<endl;
    return 0;
}




