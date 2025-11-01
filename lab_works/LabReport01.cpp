#include<bits/stdc++.h>
using namespace std;

vector<int> generateRandomN(int N, int start, int end){
    vector<int> V;
    int val;
    for(int i =0; i< N; i++){
        val = rand()%(end - start +1 ) + start;
        V.push_back(val);
    }
    return V;
}

void printList(vector<int> v){

    for(int i= 0; i< v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void bubbleSort(vector<int> &V, int N){
    int i, j;
    for(i =0; i<N ; i++){
        for(int j = 0; j < N- i- 1; j++){
            if(V[j] > V[j+1]){
                swap(V[j], V[j+1]);
            }
        }
    }
}

int main(){
    srand(time(0));
    vector<int>v;
    v = generateRandomN(50, 10, 90);
    printList(v);

    bubbleSort(v, 50);
    cout<<"Result of Bubble Sorting Algorithms\n ";
    printList(v);

    return 0 ;
}