#include <iostream>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;

int main() {
    // Example 1: Time a loop
    auto start1 = high_resolution_clock::now();
    
    for(int i = 0; i < 1000000; i++) {
        // Some work
    }
    
    auto end1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(end1 - start1);
    cout << "Loop time: " << duration1.count() << " microseconds" << endl;

    // Example 2: Time vector creation
    auto start2 = high_resolution_clock::now();
    
    vector<int> bigVector(1000000, 42);  // Create big vector
    
    auto end2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(end2 - start2);
    cout << "Vector creation: " << duration2.count() << " microseconds" << endl;

    return 0;
}