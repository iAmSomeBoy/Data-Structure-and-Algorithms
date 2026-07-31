#include<bits/stdc++.h>
using namespace std;

const int MAXN = 105;      // 100+ elements এর জন্য জায়গা
const int MAXLOG = 7;      // log2(100) ~ 6.64, তাই 7 রাখা নিরাপদ

int A[MAXN];
int table[MAXLOG][MAXN];   // table[i][j] = index j থেকে 2^i সাইজের রেঞ্জের min
int N;                     // মোট elements সংখ্যা
int LOG;                   // log2(N)

void buildSparseTable()
{
    LOG = (int)log2(N);

    // Base case: table[0][j] = A[j]  (সাইজ 2^0 = 1)
    for(int j = 1; j <= N; j++)
        table[0][j] = A[j];

    // বড় রেঞ্জ = দুইটা অর্ধেক ছোট রেঞ্জের min
    for(int i = 1; i <= LOG; i++)
    {
        int k = (1 << (i - 1));   // আগের লেভেলের সাইজ = 2^(i-1)
        for(int j = 1; j + (1 << i) - 1 <= N; j++)
        {
            table[i][j] = min( table[i-1][j], table[i-1][j + k] );
        }
    }
}

// Range [l, r] এর মধ্যে minimum বের করা - O(1)
int query(int l, int r)
{
    int len = r - l + 1;
    int k = (int)log2(len);        // সবচেয়ে বড় power of 2 যেটা len এর ভিতরে আঁটে
    return min( table[k][l], table[k][r - (1 << k) + 1] );
}

void print()
{
    for(int i = 0; i <= LOG; i++)
    {
        for(int j = 1; j <= N; j++)
        {
            if(table[i][j] == 0 && j + (1<<i) - 1 > N) cout << "-  ";
            else cout << table[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

int main()
{
    N = 100;

    
    srand(42);
    for(int i = 1; i <= N; i++)
        A[i] = rand() % 1000 + 1;

    buildSparseTable();

    cout << "Array size: " << N << endl;
    cout << "Min of range [1, 100]: " << query(1, 100) << endl;
    cout << "Min of range [5, 90]: " << query(5, 90) << endl;
    cout << "Min of range [20, 45]: " << query(20, 45) << endl;
    cout << "Min of range [1, 1]: " << query(1, 1) << endl;

    return 0;
}