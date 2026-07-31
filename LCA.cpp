#include<bits/stdc++.h>
using namespace std;

const int MAXN = 10005;
const int MAXLOG = 20;      // 2^20 > 10^5, tree এর জন্য যথেষ্ট

vector<int> g[MAXN];
int depth_[MAXN];               
int parent_[MAXLOG][MAXN];

// ধাপ ১: DFS দিয়ে প্রতিটা node এর depth আর direct parent (2^0 ধাপ উপরে) বের করা
void dfs(int v, int par, int d)
{
    depth_[v] = d;
    parent_[0][v] = par;       // base case, ঠিক sparse table এর table[0][j]=A[j] এর মতো

    for(auto u : g[v])
    {
        if(u == par) continue;  // parent এর দিকে আবার ফিরে যাওয়া ঠেকানো
        dfs(u, v, d + 1);
    }
}

// ধাপ ২: Binary Lifting Table বানানো (এটাই মূলত Sparse Table এর মতো DP)
void buildSparseTable(int n)
{
    for(int i = 1; i < MAXLOG; i++)          // hint: log(n) না লিখে fixed MAXLOG পর্যন্ত লুপ চালানো নিরাপদ
    {
        for(int j = 1; j <= n; j++)
        {
            if(parent_[i-1][j] != -1)
            {
                // hint: j থেকে 2^i ধাপ উপরে যাওয়া মানে,
                // প্রথমে 2^(i-1) ধাপ যাও, তারপর সেখান থেকে আরও 2^(i-1) ধাপ যাও
                parent_[i][j] = parent_[i-1][ parent_[i-1][j] ];
            }
            else
            {
                parent_[i][j] = -1;   // hint: root এর উপরে আর কিছু নেই, তাই -1 ই থাকুক
            }
        }
    }
}

// ধাপ ৩: LCA বের করা - O(log n) সময়ে
int findLCA(int u, int v)
{
    if(depth_[u] < depth_[v])
        swap(u, v);              // hint: u কে সবসময় গভীরে (বা সমান) রাখা সুবিধাজনক

    int diff = depth_[u] - depth_[v];

    // ধাপ ৩.১: u কে উপরে তুলে v এর সমান depth এ আনা
    for(int i = 0; i < MAXLOG; i++)
    {
        if((diff >> i) & 1)      // hint: diff কে বাইনারিতে ভেঙে দেখা, কোন কোন bit 1
        {
            u = parent_[i][u];
        }
    }

    if(u == v)
        return u;                 // hint: v আসলে u এর ancestor ছিল, তাই মিলে গেলো এখানেই

    // ধাপ ৩.২: দুইজনকে একসাথে উপরে তোলা, যতক্ষণ না parent মিলে যায়
    for(int i = MAXLOG - 1; i >= 0; i--)
    {
        if(parent_[i][u] != -1 && parent_[i][u] != parent_[i][v])
        {
            // hint: এখনো parent আলাদা মানে এখনো তারা মিলেনি, তাই লাফ দাও
            u = parent_[i][u];
            v = parent_[i][v];
        }
    }

    return parent_[0][u];         // hint: শেষে u,v এর ঠিক এক ধাপ উপরের parent-ই LCA
}

int main()
{
    int n, q;
    cin >> n >> q;

    for(int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    memset(depth_, -1, sizeof depth_);
    memset(parent_, -1, sizeof parent_);

    dfs(1, -1, 0);          // hint: root ধরে নিলাম node 1, parent -1, depth 0
    buildSparseTable(n);

    while(q--)
    {
        int u, v;
        cin >> u >> v;
        cout << findLCA(u, v) << endl;
    }

    return 0;
}
/*
Sample input:
8 5
1 2
2 3
3 4
2 6
6 7
7 8
3 5

Queries (input এর পরের অংশ, প্রশ্ন হিসেবে দাও):
4 5   -> LCA হবে 3
4 8   -> LCA হবে 2
5 7   -> LCA হবে 2
1 8   -> LCA হবে 1
6 4   -> LCA হবে 2
*/