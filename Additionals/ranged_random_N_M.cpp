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

void printUnsortedList(vector<int> v){

    for(int i= 0; i< v.size(); i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int>v;
    v = generateRandomN(50, 10, 90);

    printUnsortedList(v);

    return 0 ;
}