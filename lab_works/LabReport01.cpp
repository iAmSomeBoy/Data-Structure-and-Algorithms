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

// Bubble Sort algorithm
void bubbleSort(vector<int>& V) {
    int N = V.size();
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N - i - 1; j++) {
            if(V[j] > V[j+1]) {
                swap(V[j], V[j+1]);
            }
        }
    }
}

// Insertion sort algorithm
void insertionSort(vector<int> &V2){
    int i, j;
    for(i = 1; i < V2.size(); i++){
        j = i;
        while(j > 0 && V2[j] < V2[j-1]){
            swap(V2[j], V2[j-1]);
            j--;
        }
    }
}

// Selection sort algorithm
void selectionSort(vector<int> &V3){
    int i, j, min;
    for(i = 0; i < V3.size(); i++){
        min = i;
        for(j = i + 1; j < V3.size(); j++){
            if(V3[j] < V3[min]){
                min = j;
            }
        }
        swap(V3[i], V3[min]);
    }
}

// Using STL sort
void sorT(vector<int> &V4){
    sort(V4.begin(), V4.end());
}

int main() {
    srand(360);
    
    // Different input sizes to test
    int sizes[] = {50, 100, 500, 1000, 5000, 10000, 50000, 100000};
    int numSizes = sizeof(sizes) / sizeof(sizes[0]);
    
    // Generate all test data first
    vector<vector<int>> testData(numSizes);
    for(int i = 0; i < numSizes; i++) {
        int N = sizes[i];
        testData[i] = generateRandomNum(N, 1, 10000);
    }

    //--------- Bubble Sort -------------//
    cout << "Bubble Sort Execution Times:" << endl;
    cout << "Size of Entries\t\tTime(ms)" << endl;
    cout << "----------------------------------" << endl;
    for(int i = 0; i < numSizes; i++) {
        int N = sizes[i];
        
        vector<int> toSort1 = testData[i];  // Use pre-generated data
        
        // Time the bubble sort
        auto start_bubble = high_resolution_clock::now();
        bubbleSort(toSort1);
        auto end_bubble = high_resolution_clock::now();
        
        // Calculate duration
        auto duration_for_bubble = duration_cast<milliseconds>(end_bubble - start_bubble);
        
        cout << " " << N << "\t.............. \t " << duration_for_bubble.count() << " ms" << endl;
    }
    cout << endl;

    //------------ Insertion Sort --------------//
    cout << "Insertion Sort Execution Times:" << endl;
    cout << "Size of Entries\t\tTime(ms)" << endl;
    cout << "----------------------------------" << endl;
    for(int i = 0; i < numSizes; i++) {
        int N = sizes[i];
        
        vector<int> toSort2 = testData[i];  // Use pre-generated data
        
        // Time for the insertion sort
        auto start_insertion = high_resolution_clock::now();
        insertionSort(toSort2);
        auto end_insertion = high_resolution_clock::now();
        
        // Calculate duration
        auto duration_for_insertion = duration_cast<milliseconds>(end_insertion - start_insertion);
        cout << " " << N << "\t.............. \t " << duration_for_insertion.count() << " ms" << endl;
    }
    cout << endl;

    //-------- Selection Sort -----------//
    cout << "Selection Sort Execution Times:" << endl;
    cout << "Size of Entries\t\tTime(ms)" << endl;
    cout << "----------------------------------" << endl;
    for(int i = 0; i < numSizes; i++) {
        int N = sizes[i];
        
        vector<int> toSort3 = testData[i];  // Use pre-generated data
        
        // Time for the selection sort
        auto start_selection = high_resolution_clock::now();
        selectionSort(toSort3);
        auto end_selection = high_resolution_clock::now();
        
        // Calculate duration
        auto duration_for_selection = duration_cast<milliseconds>(end_selection - start_selection);
        cout << " " << N << "\t.............. \t " << duration_for_selection.count() << " ms" << endl;
    }
    cout << endl;

    //--------- STL sort --------------//
    cout << "STL Sort Execution Times:" << endl;
    cout << "Size of Entries\t\tTime(ms)" << endl;
    cout << "----------------------------------" << endl;
    for(int i = 0; i < numSizes; i++) {
        int N = sizes[i];
        vector<int> toSort4 = testData[i];  // Use pre-generated data
        
        // Time for the STL sort
        auto start_STL = high_resolution_clock::now();
        sorT(toSort4);
        auto end_STL = high_resolution_clock::now();
        
        // Calculate duration
        auto duration_for_STL = duration_cast<milliseconds>(end_STL - start_STL);
        cout << " " << N << "\t.............. \t " << duration_for_STL.count() << " ms" << endl;
    }  
       
    return 0;
}