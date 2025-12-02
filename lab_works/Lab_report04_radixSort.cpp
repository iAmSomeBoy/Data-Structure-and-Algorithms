#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <algorithm>
using namespace std;
using namespace std::chrono;

// Function to generate random numbers
vector<int> generateRandomNum(int N, int start, int end) {
    vector<int> v;
    for(int i = 0; i < N; i++) {
        int val = start + rand() % (end - start + 1);
        v.push_back(val);
    }
    return v;
}

// Function to print vector
void printVector(vector<int> &v) {
    for(auto num : v) {
        cout << num << " ";
    }
    cout << endl;
}

// Counting Sort
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

// A utility function to get maximum value in arr[]
int getMax(vector<int>& arr) {
    int mx = arr[0];
    for (int i = 1; i < arr.size(); i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// A function to do counting sort of arr[] according to the digit represented by exp.
void countSort(vector<int>& arr, int exp) {
    int n = arr.size();
    
    // Output array
    vector<int> output(n);
    int count[10] = {0};

    // Store count of occurrences in count[]
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Change count[i] so that count[i] now contains actual position of this digit in output[]
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Copy the output array to arr[], so that arr[] now contains sorted numbers according to current digit
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// The main function to that sorts arr[] using Radix Sort
vector<int> radixSort(vector<int> arr) {
    // Find the maximum number to know number of digits
    int m = getMax(arr);

    // Do counting sort for every digit.
    // Note that instead of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, exp);
    
    return arr;
}

int main() {
    srand(360);
    
    // Different input sizes to test
    int sizes[] = {50, 100, 500, 1000, 5000, 10000, 50000, 100000, 200000, 500000, 800000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    // Generate all test data first
    vector<vector<int>> testData(numSizes);
    for(int i = 0; i < numSizes; i++) {
        int N = sizes[i];
        testData[i] = generateRandomNum(N, 1, 65536);
    }

    //--------- Counting Sort -------------//
    cout << "Counting Sort Execution Times:" << endl;
    cout << "Size of Entries\t\tTime(ms)" << endl;
    cout << "----------------------------------" << endl;
    for(int i = 0; i < numSizes; i++) {
        int N = sizes[i];
        
        vector<int> toSort1 = testData[i];  // Use pre-generated data
        
        // Time the Counting sort
        auto start_Count = high_resolution_clock::now();
        countingSort(toSort1);
        auto end_Count = high_resolution_clock::now();
        
        // Calculate duration
        auto duration_for_Count = duration_cast<milliseconds>(end_Count - start_Count);
        
        cout << " " << N << "\t.............. \t " << duration_for_Count.count() << " ms" << endl;
    }
    cout << endl;

    //--------- Radix Sort -------------//
    cout << "Radix Sort Execution Times:" << endl;
    cout << "Size of Entries\t\tTime(ms)" << endl;
    cout << "----------------------------------" << endl;
    for(int i = 0; i < numSizes; i++) {
        int N = sizes[i];
        
        vector<int> toSort2 = testData[i];  // Use pre-generated data
        
        // Time the Radix sort
        auto start_Radix = high_resolution_clock::now();
        radixSort(toSort2);
        auto end_Radix = high_resolution_clock::now();
        
        // Calculate duration
        auto duration_for_Radix = duration_cast<milliseconds>(end_Radix - start_Radix);
        
        cout << " " << N << "\t.............. \t " << duration_for_Radix.count() << " ms" << endl;
    }
    cout << endl;
       
    return 0;
}