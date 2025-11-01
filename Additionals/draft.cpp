#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<chrono>
using namespace std;
using namespace std::chrono;
vector<int>generateRandomNum(int N, int start, int ed)
{
    vector<int>v;
    int val;
    srand(343);
    for(int i=0; i<N; i++)
    {
        val = start + rand()%(ed-start+1);
        v.push_back(val);
    }
    return v;
}
void printVector(vector<int>v)
{
    for(auto i:v)
    {
        cout<<i<<" ";
    }
    cout<<endl;

}

int main()
{
    vector<int>V;
    int arr[10] = {10, 100, 500, 1000, 5000, 10000, 50000};
    for(int i=0; i<10; i++)
    {
        int N = arr[i];
        auto start = high_resolution_clock::now();
        V = generateRandomNum(N, 1, 100);
        auto last = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(last-start);
        cout<<N<<": "<<duration.count()<<endl;
    }
    return 0;
}