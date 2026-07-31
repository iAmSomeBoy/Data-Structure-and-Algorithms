#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
int n;
int ara[MAXN];
int tree[4*MAXN]; //  needs 4*n size, not 10000

void build(int node, int b, int e) {
    if(b==e) {
        tree[node] = ara[b];
        return;
    }
    int mid = (b+e)/2;
    build(2*node, b, mid);
    build(2*node+1, mid+1, e);
    tree[node] = min(tree[2*node], tree[2*node+1]);
}

int query(int node, int b, int e, int l, int r) {
    if(r < b || l > e) {
        return INT_MAX; // no overlap
    }
    if(b >= l && e <= r) { 
        return tree[node]; // total overlap
    }
    int mid = (b+e)/2;
    int leftres  = query(2*node,   b, mid, l, r);
    int rightres = query(2*node+1, mid+1, e, l, r);
    return min(leftres, rightres);
}

int main() {
    cout << "Enter the number of elements : ";
    cin >> n;

    cout << "Input array : ";
    for(int i=0; i<n; i++) cin >> ara[i];

    build(1, 0, n-1);

    int q;
    cout << "Enter number of queries: ";
    cin >> q;

    for(int i=0; i<q; i++) {
        int l, r;
        cout << "Enter range (Left Right, 0-indexed): ";
        cin >> l >> r;
        cout << i << " : " << query(1, 0, n-1, l, r) << endl;
    }
    return 0;
}