#include <bits/stdc++.h>
#include <vector>
using namespace std;

void heapify(vector<int>& array, int currentIdx, int endIdx) {
    int leftChildIdx = 2 * currentIdx + 1;
    
    while (leftChildIdx <= endIdx) {
        int rightChildIdx = 2 * currentIdx + 2;
        int largestChildIdx = leftChildIdx;
        
        // Check if right child exists and is larger than left child
        if (rightChildIdx <= endIdx && array[leftChildIdx] < array[rightChildIdx]) {
            largestChildIdx = rightChildIdx;
        }
        
        // If current node is smaller than largest child, swap and continue
        if (array[currentIdx] < array[largestChildIdx]) {
            swap(array[currentIdx], array[largestChildIdx]);
            currentIdx = largestChildIdx;
            leftChildIdx = 2 * currentIdx + 1;
        } else {
            return;
        }
    }
}

void maxHeap(vector<int>& array) {
    // Build max heap
    int lastNonLeafNodeIdx = (array.size() - 2) / 2;
    for (int currentIdx = lastNonLeafNodeIdx; currentIdx >= 0; currentIdx--) {
        heapify(array, currentIdx, array.size() - 1);
    }
    
    // Extract elements from heap one by one
    for (int endIdx = array.size() - 1; endIdx > 0; endIdx--) {
        swap(array[0], array[endIdx]);
        heapify(array, 0, endIdx - 1);
    }
}


int main() {
    vector<int> array = {1, -15, 22, 40, 9, 91};
    
    cout << "Original array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
    
    maxHeap(array);
    
    cout << "Sorted array: ";
    for (int num : array) {
        cout << num << " ";
    }
    cout << endl;
    
    return 0;
}