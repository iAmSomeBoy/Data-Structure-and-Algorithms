#include <bits/stdc++.h>
using namespace std;

// Stable Counting Sort (returns a new sorted array)
vector<int> countingSort(const vector<int>& array) {
    // Step 1.a: find maximum value
    int maxValue = *max_element(array.begin(), array.end());

    // Step 1.b: create counts array
    vector<int> counts(maxValue + 1, 0);

    // Step 2: count frequency of each element
    for(int num : array) {
        counts[num]++;
    }

    // Step 3: convert frequency to cumulative counts
    for(int i = 1; i < counts.size(); i++) {
        counts[i] += counts[i - 1];
    }

    // Step 4: create output array
    vector<int> sortedArray(array.size());

    // Step 5: place elements into sortedArray (iterate backwards to keep stability)
    for(int i = array.size() - 1; i >= 0; i--) {
        int element = array[i];
        int position = counts[element];  // cumulative position
        sortedArray[position - 1] = element;
        counts[element]--;               // reduce position for duplicates
    }

    return sortedArray;
} 

int main() {
    vector<int> array = {9, 5, 2, 4, 2, 8, 5};

    vector<int> sorted = countingSort(array);

    cout << "Stable Counting Sort Output: ";
    for(int x : sorted) cout << x << " ";
    cout << endl;

    return 0;
}
