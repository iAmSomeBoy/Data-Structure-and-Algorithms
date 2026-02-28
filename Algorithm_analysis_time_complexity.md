# Algorithm Time Complexity Analysis Guide

## Introduction

When analyzing the time complexity of an algorithm, you don't need to count every single statement. We only consider statements that increase the execution count.

---

## 📊 Key Operations to Consider

### 1️⃣ Assignment Operation

Assigning values to variables.

```c
a = 5;
sum = sum + i;
```

**Complexity:** O(1)

---

### 2️⃣ Arithmetic Operation

Mathematical operations.

```c
a + b
a * b
a / b
```

**Complexity:** O(1)

---

### 3️⃣ Comparison Operation

Checking conditions.

```c
if(a > b)
if(i < n)
```

**Complexity:** O(1), but can execute n times if used in a loop condition.

---

### 4️⃣ Loop Statements

**Most Important!**

```c
for(int i=0; i<n; i++)
```

- **Single Loop:** O(n)
- **Nested Loop:** O(n²)

---

### 5️⃣ Recursion Call

When a function calls itself.

```c
f(n-1)
```

Use recursion trees or recurrence relations to determine complexity.

**Examples:**
- Fibonacci: O(2ⁿ)
- Merge Sort: O(n log n)

---

### 6️⃣ Function Calls

When calling a function, its complexity is added to the total.

**Example:**
```c
sort(arr, arr+n);  // O(n log n)
```

---

### 7️⃣ Data Structure Operation

Each data structure has different operation costs.

| Operation | Complexity |
|-----------|-----------|
| vector push_back | O(1) amortized |
| map insert | O(log n) |
| unordered_map insert | O(1) average |
| priority_queue push | O(log n) |

---

### 8️⃣ Input / Output

Generally O(1), but multiplies when inside a loop.

```c
for(i=0; i<n; i++)
   cin >> a[i];
```

**Complexity:** O(n)

---

## ❗ What to Ignore

Constant operations are ignored because they don't impact final complexity.

**Example:**
```c
int a = 5;
int b = 10;
```

These are O(1) and don't affect the final complexity calculation.

---

## 🎯 Quick Analysis Rule (Exam Trick)

When analyzing algorithms, check:

1. ✓ How many loops are there?
2. ✓ Are there nested loops?
3. ✓ Is there recursion?
4. ✓ Are there expensive function calls inside (sort, map, etc.)?

---

## 🔥 10 Common Patterns - Instant Recognition

### 🚀 Pattern 1: Simple Linear Loop

```c
for(int i=0; i<n; i++)
    cout << i;
```

**Complexity:** **O(n)**

One loop runs n times.

---

### 🚀 Pattern 2: Nested Loop (Same Range)

```c
for(int i=0; i<n; i++)
   for(int j=0; j<n; j++)
       cout << i+j;
```

**Complexity:** **O(n²)**

n × n iterations.

---

### 🚀 Pattern 3: Triangular Loop

```c
for(int i=0; i<n; i++)
   for(int j=0; j<i; j++)
       cout << i+j;
```

**Complexity:** **O(n²)**

Total iterations ≈ n(n-1)/2, which is still O(n²).

---

### 🚀 Pattern 4: Loop Halving (Logarithmic)

```c
for(int i=n; i>0; i/=2)
    cout << i;
```

**Complexity:** **O(log n)**

The value halves with each iteration.

---

### 🚀 Pattern 5: Double Log Pattern

```c
for(int i=1; i<n; i*=2)
   for(int j=1; j<n; j*=2)
       cout << i+j;
```

**Complexity:** **O((log n)²)**

Both loops are logarithmic.

---

### 🚀 Pattern 6: Log Inside Linear

```c
for(int i=0; i<n; i++)
{
   int x = n;
   while(x > 0)
       x /= 2;
}
```

**Complexity:** **O(n log n)**

Linear loop containing a logarithmic operation.

---

### 🚀 Pattern 7: Two Independent Loops

```c
for(int i=0; i<n; i++)
    cout << i;

for(int j=0; j<n; j++)
    cout << j;
```

**Complexity:** **O(n)**

n + n = 2n, and constants are dropped in Big-O notation.

---

### 🚀 Pattern 8: Linear Recursion

```c
f(n) {
   if(n == 0) return;
   f(n-1);
}
```

**Complexity:** **O(n)**

Function is called n times.

---

### 🚀 Pattern 9: Binary Recursion (Exponential)

```c
f(n) {
   if(n == 0) return;
   f(n-1);
   f(n-1);
}
```

**Complexity:** **O(2ⁿ)**

Two branches at each level.

---

### 🚀 Pattern 10: Divide & Conquer

```c
f(n) {
   f(n/2);
   f(n/2);
}
```

**Complexity:** **O(n)**

Using Master Theorem: 2T(n/2) = O(n)

**Examples:**
- Merge Sort: O(n log n)
- Binary Search: O(log n)

---

## 🎯 Bonus: Graph Algorithms (Exam Favorite)

| Algorithm | Time Complexity |
|-----------|-----------------|
| BFS | O(V + E) |
| DFS | O(V + E) |
| Dijkstra (with priority_queue) | O((V+E) log V) |
| Kruskal | O(E log E) |
| Prim (with heap) | O(E log V) |

---

## 🧠 Golden Shortcut Rules

| Pattern | Complexity |
|---------|-----------|
| i++ | **Linear (O(n))** |
| i*=2 or i/=2 | **Logarithmic (O(log n))** |
| Nested loops | **Multiply complexities** |
| Sequential loops | **Add complexities** |
| Recursive split | **Use Master Theorem or recurrence relation** |

---

## Quick Reference Table

| Code Pattern | Complexity |
|-------------|-----------|
| Single loop: `for(i=0; i<n; i++)` | O(n) |
| Double loop: `for(i=0; i<n; i++) for(j=0; j<n; j++)` | O(n²) |
| Loop halving: `for(i=n; i>0; i/=2)` | O(log n) |
| Linear + Log: `for(i=0; i<n; i++) while(x>0) x/=2` | O(n log n) |
| Binary tree recursion | O(2ⁿ) |
| Divide & Conquer (balanced split) | O(n log n) |

---

## Tips for Exam Success

✅ Always identify the **dominant loop** or **recursive structure**

✅ **Ignore constants** — 2n = O(n), 3n² + 5n = O(n²)

✅ **Nested operations multiply** — O(n) inside O(n) = O(n²)

✅ **Sequential operations add** — O(n) + O(n) = O(n)

✅ **Ignore lower-order terms** — O(n² + n) = O(n²)

✅ **Data structure operations matter** — Know std::map, unordered_map, priority_queue complexities

✅ **Graph problems** — Remember O(V+E) for BFS/DFS, O((V+E) log V) for Dijkstra

---

**Happy coding! 🚀**