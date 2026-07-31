#include <bits/stdc++.h>
using namespace std;

const int MAXN = 10000;
int n;
long long ara[MAXN];
long long tree[4*MAXN];
long long lazy_[4*MAXN]; // named lazy_ to avoid clash with keyword-like usage

void build(int node, int b, int e) {
    if(b==e) {
        tree[node] = ara[b];
        return;
    }
    int mid = (b+e)/2;
    build(2*node, b, mid);
    build(2*node+1, mid+1, e);
    tree[node] = tree[2*node] + tree[2*node+1];
}

// push pending lazy value down before touching this node's children
void pushDown(int node, int b, int e) {
    if(lazy_[node] != 0) {
        tree[node] += (long long)(e-b+1) * lazy_[node];
        if(b != e) { // not a leaf, pass lazy to children
            lazy_[2*node]   += lazy_[node];
            lazy_[2*node+1] += lazy_[node];
        }
        lazy_[node] = 0;
    }
}

// add val to every element in range [l, r]
void update(int node, int b, int e, int l, int r, long long val) {
    pushDown(node, b, e);
    if(r < b || l > e) return; // no overlap
    if(b >= l && e <= r) {     // total overlap
        lazy_[node] += val;
        pushDown(node, b, e);
        return;
    }
    int mid = (b+e)/2;
    update(2*node,   b, mid,   l, r, val);
    update(2*node+1, mid+1, e, l, r, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

// sum of range [l, r]
long long query(int node, int b, int e, int l, int r) {
    pushDown(node, b, e);
    if(r < b || l > e) return 0; // no overlap
    if(b >= l && e <= r) return tree[node]; // total overlap
    int mid = (b+e)/2;
    long long leftres  = query(2*node,   b, mid,   l, r);
    long long rightres = query(2*node+1, mid+1, e, l, r);
    return leftres + rightres;
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

    while(q--) {
        cout << "Enter 'q' for query, 'u' for update: ";
        char c; cin >> c;
        cout << "Enter range (Left Right, 0-indexed): ";
        int l, r; cin >> l >> r;

        if(c == 'q') {
            cout << "Sum : " << query(1, 0, n-1, l, r) << endl;
        } else {
            cout << "Enter value to add: ";
            long long val; cin >> val;
            update(1, 0, n-1, l, r, val);
            cout << "OK" << endl;
        }
    }
    return 0;
}