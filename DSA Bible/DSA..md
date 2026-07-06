# 🧠 THE DSA BIBLE — C++ Implementation Handbook for Interviews & Competitive Programming

> **Status:** Living document, built in parts. This is **Part 1 of N**.
> Covered so far: C++ Basics → Loops → STL Core Containers (vector, pair, tuple, stack, queue, priority_queue, set family, map family).
> Remaining topics (Algorithms Library, Bit Manipulation, Prefix Sum, Sliding Window, Two Pointer, Binary Search, Sorting, Linked List, Monotonic Stack/Queue, Heap, Hashing, Strings, Trie, Recursion, Backtracking, Greedy, Trees, BST, Binary Lifting, Graphs, Union Find, Topo Sort, Shortest Path, MST, DP, Segment Tree, Fenwick Tree, Sparse Table, Math, Number Theory, Geometry, Game Theory, Advanced DS, CP Tricks) will be appended in the next parts — say "continue" and I'll keep building.

This is **not a tutorial**. Theory is kept to 2–5 lines. Everything else is implementation: syntax, complexities, edge cases, templates, dry runs, and contest tricks you can copy-paste under time pressure.

All code is **C++17**.

---

## 📑 Table of Contents

- [1. C++ Basics](#1-c-basics)
- [2. Loops](#2-loops)
- [3. STL Complete](#3-stl-complete)
  - [3.1 vector](#31-vector)
  - [3.2 pair](#32-pair)
  - [3.3 tuple](#33-tuple)
  - [3.4 stack](#34-stack)
  - [3.5 queue](#35-queue)
  - [3.6 priority_queue](#36-priority_queue)
  - [3.7 set / multiset](#37-set--multiset)
  - [3.8 map / multimap](#38-map--multimap)
  - [3.9 unordered_set / unordered_map](#39-unordered_set--unordered_map)
- *(Sections 4–42: coming in Part 2 onward)*

---

## 1. C++ Basics

### 1.1 Variables, Data Types & Fast IO

**Concept:** Variables are typed storage locations. Choose the smallest type that safely holds your range to save memory and avoid overflow bugs — the #1 silent killer in CP.

**Time/Space:** O(1) access, O(1) memory per primitive.

| Type | Size | Range | CP Use |
|---|---|---|---|
| `int` | 4 bytes | ±2.1×10⁹ | default counters |
| `long long` | 8 bytes | ±9.2×10¹⁸ | **always use for sums/products that can exceed 10⁹** |
| `unsigned long long` | 8 bytes | 0 to 1.8×10¹⁹ | modular arithmetic, bit tricks |
| `double` / `long double` | 8/16 bytes | ~15-18 sig figs | geometry, probability |
| `char` | 1 byte | -128 to 127 | strings, ASCII |
| `bool` | 1 byte | 0/1 | flags, visited arrays |

```cpp
#include <bits/stdc++.h>
using namespace std;

// Fast IO — put this at the top of main() in EVERY contest submission
static void fastIO() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int main() {
    fastIO();
    long long a, b;
    cin >> a >> b;
    cout << a + b << "\n";  // '\n' not endl — endl flushes, slower for large output
}
```

**Common Mistakes:**
- Using `int` for sums where `n ≤ 1e5` and values `≤ 1e9` → product/sum overflows `int` (max ~2.1e9). Use `long long`.
- Forgetting `fastIO()` → TLE on large I/O (10⁵+ lines).
- Using `endl` in tight loops instead of `"\n"` → unnecessary flush overhead.
- Mixing `%d` with `long long` in `scanf` — must use `%lld`.

**Interview Tip:** In interviews (unlike CP), explicitly state your assumption about integer overflow — interviewers reward this awareness.

---

### 1.2 Macros, typedef, using

**Concept:** Compile-time text substitution (`#define`) vs type aliasing (`typedef`/`using`). `using` is the modern, scope-safe preferred way in C++17.

```cpp
// typedef (old style)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

// using (C++11+, preferred — supports templates)
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
template<typename T> using vec = vector<T>; // typedef CANNOT do this, using CAN

// Common contest macros
#define endl '\n'
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define ff first
#define ss second
#define sz(x) (int)(x).size()
#define fr(i,a,b) for(int i=(a); i<(b); i++)
#define rf(i,a,b) for(int i=(a); i>=(b); i--)
```

**Common Mistakes:**
- `#define endl '\n'` conflicts with actual `std::endl` semantics if you rely on flushing anywhere (e.g., interactive problems) — remove this macro for interactive problems.
- Macros don't respect scope/namespaces — can silently break unrelated code. Prefer `using`/`const`/`inline function` over macros in real (non-CP) code.
- `#define SQ(x) x*x` → `SQ(a+b)` expands to `a+b*a+b` (missing parens bug). Always macro-wrap args: `#define SQ(x) ((x)*(x))`.

---

### 1.3 const, constexpr, References, Pointers

**Concept:** `const` = runtime-immutable, `constexpr` = compile-time-evaluated (faster, usable as array size). References are aliases (no new memory); pointers hold addresses and can be null/reseated.

```cpp
const int MOD = 1e9 + 7;              // known at compile OR runtime
constexpr int N = 100005;             // MUST be compile-time; usable for array size
int arr[N];                           // valid because N is constexpr

int x = 10;
int &ref = x;      // reference: ref IS x, no separate address
ref = 20;          // x is now 20

int *ptr = &x;      // pointer: holds address of x
*ptr = 30;          // dereference: x is now 30
ptr = nullptr;      // pointers can be null; references cannot
```

**Common Mistakes:**
- Trying `int arr[n]` where `n` is a `const int` set from user input → compile error on some compilers (VLA extension only works on GCC, not standard C++, not on MSVC). Use `constexpr` only with true compile-time constants, else use `vector`.
- Dangling reference/pointer: returning a reference to a local variable.
- Forgetting `nullptr` check before dereferencing a pointer → UB/crash.

**Interview Tip:** Know the difference cold — "reference vs pointer" is a classic C++ interview question. Key line: *"References must be initialized and can't be null or reassigned; pointers can be reassigned, can be null, and support pointer arithmetic."*

---

### 1.4 Arrays, Strings, Char Arrays

**Concept:** Raw arrays are fixed-size, contiguous, fast. `std::string` is a dynamic, mutable char sequence with rich member functions — prefer it over `char[]` in almost all CP/interview code.

```cpp
int arr[5] = {1,2,3,4,5};
int arr2[5] = {};          // zero-initialized
int arr3[100005];          // global/static arrays auto zero-initialized; LOCAL ones are NOT

string s = "hello";
s += " world";              // "hello world"
s[0] = 'H';                  // mutate: "Hello world"
char c = s.back();           // last char
string sub = s.substr(1, 3); // "ell" (start=1, len=3)

char carr[100];
strcpy(carr, s.c_str());     // string -> char array
string s2(carr);              // char array -> string
```

**Common Mistakes:**
- Local (stack) array `int arr[100005];` inside a function is **garbage-initialized**, not zero. Global/static arrays ARE zero-initialized.
- Array size declared with a variable (not constexpr) on non-GCC compilers → compile error (Codeforces uses GCC/MSVC — check judge!).
- `strcpy` buffer overflow if destination too small.
- Comparing `char*` with `==` compares pointers, not content — use `strcmp` or just use `std::string`.

**Edge Cases:** empty string `""`, single character, string with all same characters, string with only one distinct type of char.

---

### 1.5 Functions, Lambda, Recursion

**Concept:** Functions encapsulate logic; lambdas are anonymous inline functions (essential for custom comparators); recursion solves problems via self-calls with a base case.

```cpp
// Regular function
int add(int a, int b) { return a + b; }

// Lambda — capture by value [x], by reference [&x], or all [&]
auto add2 = [](int a, int b) -> int { return a + b; };
int total = 0;
auto accumulate_ = [&total](int x) { total += x; }; // captures by reference

// Lambda as custom comparator (very common in CP)
vector<pair<int,int>> v = {{1,5},{2,3}};
sort(v.begin(), v.end(), [](const pair<int,int>&a, const pair<int,int>&b){
    return a.second < b.second; // sort by second element ascending
});

// Recursion with memoization signature
int memo[100005];
int fib(int n) {
    if (n <= 1) return n;                 // base case
    if (memo[n] != -1) return memo[n];    // memo check
    return memo[n] = fib(n-1) + fib(n-2); // recursive case + store
}
```

**Common Mistakes:**
- Forgetting the base case → stack overflow (infinite recursion).
- Capturing large objects by value `[=]` in lambdas inside hot loops → performance hit; capture by reference `[&]` when safe.
- Recursion depth > ~10⁴–10⁵ on default stack → runtime error (segfault) on deep recursion (e.g., DFS on a skewed tree of 10⁵ nodes). Convert to iterative + explicit stack, or increase stack size if allowed.

**CP Trick:** Default recursion limit is your best friend's enemy — for `n > 10^5` depth trees, always have an iterative DFS template ready.

---

### 1.6 Namespaces, Header Files, File Structure

**Concept:** `namespace` avoids naming collisions; `using namespace std;` is fine for CP but avoided in production multi-file codebases (name pollution).

```cpp
namespace mymath {
    int square(int x) { return x*x; }
}
int y = mymath::square(5);

// Typical competitive file skeleton
#include <bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    // per-test-case logic
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(nullptr);
    int t; cin >> t;
    while (t--) solve();
}
```

**Interview Tip:** In production interviews, mention that `using namespace std;` at global scope is discouraged in real codebases due to symbol collisions — shows engineering maturity beyond CP habits.

---

## 2. Loops

**Concept:** Loops repeat execution. Choice of loop affects readability and micro-performance; `break`/`continue` control flow within them.

| Loop | Best For | Time Complexity |
|---|---|---|
| `for` | known iteration count | O(n) |
| `while` | unknown/condition-based count | O(n) worst |
| `do-while` | guaranteed-at-least-once execution | O(n) |
| range-based `for` | clean iteration over containers | O(n) |

```cpp
// Standard for
for (int i = 0; i < n; i++) { /* ... */ }

// Reverse for
for (int i = n-1; i >= 0; i--) { /* ... */ }

// While
int i = 0;
while (i < n) { i++; }

// Do-while (executes body at least once)
int x = 5;
do { x--; } while (x > 0);

// Range-based (C++11+) — read-only
for (int x : arr) { /* x is a copy */ }
for (int &x : arr) { x *= 2; }       // reference — mutates original
for (const auto &x : v) { /* ... */ } // avoids copies for large types

// Nested loop — O(n*m)
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++) { /* grid/matrix problems */ }

// Infinite loop (used with break for "until condition met")
while (true) {
    if (/* condition */) break;
}
```

**break vs continue vs goto:**
```cpp
for (int i = 0; i < n; i++) {
    if (arr[i] == target) break;     // exits loop entirely
    if (arr[i] < 0) continue;        // skips to next iteration
}
// goto — AVOID in normal code. Only legitimate CP use: breaking out of
// deeply nested loops (3+ levels) where break only exits the innermost.
for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        if (arr[i][j] == 0) goto done;
done:;
```

**Common Mistakes:**
- Off-by-one errors: `i <= n` vs `i < n` — always match against whether array is 0-indexed and size `n`.
- Infinite loop from forgetting to update the loop variable inside `while`.
- Modifying a container (e.g., `vector`) while range-iterating over it → undefined behavior / invalidated iterators.
- Using `goto` for anything other than multi-level loop breaks — hurts readability, flagged in code review/interviews.

**Loop Tricks (CP):**
- Multi-level break: use `goto`, or wrap in a lambda and `return`.
- Iterate a `set`/`map` in sorted order for free — no extra sort needed.
- `for (int i = 0; i < (1<<n); i++)` — iterate all subsets of an n-element set (bitmask enumeration).

---

## 3. STL Complete

### 3.1 vector

**Concept:** Dynamic contiguous array. Amortized O(1) push_back via doubling capacity. The workhorse container of competitive programming.

| Operation | Complexity |
|---|---|
| Access `v[i]` | O(1) |
| `push_back` | O(1) amortized |
| `pop_back` | O(1) |
| `insert(pos, x)` | O(n) |
| `erase(pos)` | O(n) |
| `find` (via algorithm) | O(n) |
| Sort | O(n log n) |

```cpp
vector<int> v;                     // empty
vector<int> v2(5);                 // size 5, all 0
vector<int> v3(5, 7);              // size 5, all 7
vector<int> v4 = {1,2,3};          // initializer list
vector<vector<int>> grid(n, vector<int>(m, 0)); // 2D grid n x m of zeros

v.push_back(10);                   // insert at end
v.emplace_back(10);                // construct in place — faster for objects
v.pop_back();                      // remove last
v.insert(v.begin()+2, 99);         // insert 99 at index 2 — O(n)
v.erase(v.begin()+1);              // remove index 1 — O(n)
v.erase(v.begin(), v.begin()+3);   // remove range [0,3)

int f = v.front(), b = v.back();
int sz = v.size();
bool empty = v.empty();

sort(v.begin(), v.end());                       // ascending
sort(v.begin(), v.end(), greater<int>());       // descending
sort(v.rbegin(), v.rend());                     // reverse-iterator descending
reverse(v.begin(), v.end());

v.clear();                          // size 0, capacity unchanged
v.resize(10);                        // grow/shrink, new elements = 0
v.resize(10, -1);                    // new elements = -1
v.reserve(1000);                     // pre-allocate capacity, avoids reallocations
v.assign(5, 2);                      // replace contents: 5 elements of value 2
v.shrink_to_fit();                   // release unused capacity

// Binary search (container MUST be sorted)
bool found = binary_search(v.begin(), v.end(), 5);
auto lb = lower_bound(v.begin(), v.end(), 5); // first element >= 5
auto ub = upper_bound(v.begin(), v.end(), 5); // first element > 5
int idx = lower_bound(v.begin(), v.end(), 5) - v.begin(); // as index

// erase-remove idiom — remove all elements equal to 3
v.erase(remove(v.begin(), v.end(), 3), v.end());
// remove duplicates from a SORTED vector
v.erase(unique(v.begin(), v.end()), v.end());

swap(v, v4);                         // O(1) — swaps internal pointers
```

**Dry Run — lower_bound:**
```
v = [1, 3, 3, 5, 7], target = 3
lower_bound → points to index 1 (first '3')
upper_bound → points to index 3 (value 5, first element > 3)
count of 3s = upper_bound - lower_bound = 2
```

**Common Mistakes:**
- `v.erase(v.begin()+i)` inside a `for` loop iterating forward → skips an element (indices shift). Iterate backward when erasing by index in a loop, or use erase-remove idiom.
- Using `binary_search`/`lower_bound`/`upper_bound` on an **unsorted** vector → undefined/incorrect result.
- Passing `vector<int>` by value to a function → O(n) copy; pass by `const&` unless mutation is intended.
- `v[i]` out-of-bounds → UB (no exception, unlike `v.at(i)` which throws).
- `resize()` down does NOT free memory (capacity stays) — use `shrink_to_fit()` if memory matters.

**Contest Tricks:**
- 2D vector init: `vector<vector<int>> dp(n+1, vector<int>(m+1, 0));`
- Flatten a 2D grid into 1D index: `idx = i*m + j`.
- `vector<int> v(n); iota(v.begin(), v.end(), 0);` → `[0,1,2,...,n-1]`.

---

### 3.2 pair

**Concept:** Fixed 2-element heterogeneous tuple, sorted lexicographically by default — ideal for coordinate/weighted-edge storage.

```cpp
pair<int,int> p = {1, 2};
pair<int,string> p2 = make_pair(5, "five");
cout << p.first << " " << p.second;

vector<pair<int,int>> v = {{3,1},{1,2},{2,0}};
sort(v.begin(), v.end());
// default sort: by .first ascending, ties broken by .second ascending
// result: {1,2}, {2,0}, {3,1}

// Custom comparator — sort by second descending
sort(v.begin(), v.end(), [](auto &a, auto &b){ return a.second > b.second; });

// Nested pair for 3 values
pair<int, pair<int,int>> triple = {1, {2, 3}};
```

**Common Mistakes:**
- Assuming `pair` sorts by `.second` by default — it sorts by `.first` first, then `.second`.
- Structured bindings typo: `auto [a, b] = p;` (C++17) — forgetting `auto` causes compile error.

**Interview Tip:** `pair<int,int>` is the fastest way to represent a 2D point or a (distance, node) tuple for Dijkstra's priority_queue.

---

### 3.3 tuple

**Concept:** Generalizes `pair` to N elements of possibly different types.

```cpp
tuple<int, string, double> t = {1, "abc", 3.14};
int a = get<0>(t);
string s = get<1>(t);
auto [x, y, z] = t;   // structured binding (C++17)

vector<tuple<int,int,int>> edges; // (weight, u, v) — common for MST/Kruskal
edges.push_back({5, 0, 1});
sort(edges.begin(), edges.end()); // sorts by weight first automatically
```

**Common Mistakes:**
- `get<Type>(t)` fails to compile if the type appears more than once in the tuple — use index-based `get<N>` instead.
- Forgetting tuples compare lexicographically element-by-element — great for Kruskal's (weight, u, v) sort.

---

### 3.4 stack

**Concept:** LIFO container adapter, built on `deque` by default. O(1) push/pop/top.

```cpp
stack<int> st;
st.push(1); st.push(2); st.push(3);
int t = st.top();      // 3
st.pop();               // removes 3 (no return value!)
bool e = st.empty();
int sz = st.size();

// Common pattern: check balanced parentheses
bool isValid(string s) {
    stack<char> st;
    for (char c : s) {
        if (c=='('||c=='['||c=='{') st.push(c);
        else {
            if (st.empty()) return false;
            char top = st.top(); st.pop();
            if ((c==')'&&top!='(') || (c==']'&&top!='[') || (c=='}'&&top!='{'))
                return false;
        }
    }
    return st.empty();
}
```

**Common Mistakes:**
- `st.pop()` returns `void` — calling `int x = st.pop();` is a compile error. Must `top()` then `pop()`.
- Calling `top()`/`pop()` on empty stack → UB/crash. Always check `empty()` first.

**Interview Tip:** Stack is the go-to for "matching", "undo", "next greater element", and DFS-iterative implementations.

---

### 3.5 queue

**Concept:** FIFO container adapter, O(1) push (back)/pop (front). Backbone of BFS.

```cpp
queue<int> q;
q.push(1); q.push(2);
int f = q.front();     // 1
int b = q.back();      // 2
q.pop();                 // removes front (1) — void return
bool e = q.empty();

// BFS template
vector<int> bfs(int start, vector<vector<int>>& adj, int n) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[start] = 0; q.push(start);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (dist[v] == -1) { dist[v] = dist[u] + 1; q.push(v); }
    }
    return dist;
}
```

**Common Mistakes:**
- Confusing `queue` (FIFO) with `stack`/`priority_queue` — using the wrong one silently gives wrong traversal order (DFS vs BFS mix-up).
- `q.pop()` on empty queue → UB.

---

### 3.6 priority_queue

**Concept:** Max-heap by default (largest element on top). O(log n) push/pop, O(1) top. Essential for Dijkstra, Kruskal (with sort alternative), top-K problems.

```cpp
priority_queue<int> pq;                       // max-heap
pq.push(5); pq.push(1); pq.push(9);
int top = pq.top();    // 9
pq.pop();                // removes 9

priority_queue<int, vector<int>, greater<int>> minHeap; // min-heap
minHeap.push(5); minHeap.push(1);
cout << minHeap.top();  // 1

// Min-heap of pairs (distance, node) — Dijkstra's algorithm
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq2;
pq2.push({0, start});

// Custom comparator with lambda (needs decltype trick, verbose) —
// simpler: negate values, or store pair<int,int> and use greater<>.
struct Compare {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second; // min-heap by .second
    }
};
priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq3;
```

**Dry Run — Top-K largest using min-heap of size K:**
```
nums = [3,1,5,12,2,11], k = 3
Push 3,1,5 → minHeap = {1,3,5} (top=1)
Push 12: 12>1, pop 1, push 12 → {3,5,12} (top=3)
Push 2: 2<3, skip
Push 11: 11>3, pop 3, push 11 → {5,11,12}
Result: 3 largest = {5,11,12}
```

**Common Mistakes:**
- Forgetting `priority_queue` is **max-heap by default** — a common source of bugs when a min-heap was intended.
- Declaring min-heap syntax wrong — must be `priority_queue<T, vector<T>, greater<T>>`, not just `greater<T>` alone.
- `pq.pop()` returns void; `top()` first to read the value.
- No `O(1)` way to remove an arbitrary (non-top) element — need "lazy deletion" trick (mark deleted, skip when popped) if required.

**CP Trick:** For a min-heap of custom struct without writing a comparator class, push negated values into a max-heap: `pq.push(-x);` and negate again on pop.

---

### 3.7 set / multiset

**Concept:** `set` = sorted, unique elements, balanced BST (Red-Black Tree) underneath. `multiset` allows duplicates. O(log n) insert/erase/find.

```cpp
set<int> s = {5, 1, 3};
s.insert(4);                 // {1,3,4,5} — auto-sorted
s.erase(3);                   // remove value 3
bool found = s.count(4);      // 1 if present, 0 if not (use count, NOT find==end for clarity)
auto it = s.find(5);          // iterator to 5, or s.end() if absent

// Ordered traversal — free sorted iteration
for (int x : s) cout << x << " ";

auto lb = s.lower_bound(4);   // iterator to first element >= 4
auto ub = s.upper_bound(4);   // iterator to first element > 4

int mn = *s.begin();
int mx = *s.rbegin();

multiset<int> ms = {1,1,2,2,3};
ms.erase(ms.find(1));          // erases ONE instance of 1
// ms.erase(1);                 // WARNING: erases ALL instances of 1!
cout << ms.count(2);           // 2
```

**Common Mistakes:**
- `s.erase(value)` on `multiset` removes **all** occurrences, not one. Use `ms.erase(ms.find(value))` to remove a single instance.
- Using `set::find` and comparing `!= s.end()` when `s.count(x)` reads cleaner (though `find` is marginally faster since `count` internally still does a search — for `set` either is O(log n)).
- Attempting `s[i]` indexing — `set` has no `operator[]` or random access; iterators are not `+k` jumpable in O(1) (must advance one by one, O(k)).
- Modifying an element in-place via iterator — not allowed (would break ordering invariant); must erase + reinsert.

**Contest Tricks:**
- `set<int>` + `lower_bound` = poor man's balanced BST for "find nearest ≥ x" queries in O(log n).
- **Ordered Set trick (GNU PBDS)** for O(log n) order-statistics (find k-th smallest, find rank of x) — see Section 42.

---

### 3.8 map / multimap

**Concept:** Sorted key-value store, unique keys (`map`) or duplicate keys allowed (`multimap`). O(log n) operations, red-black tree backed.

```cpp
map<string,int> m;
m["apple"] = 5;                 // insert or update
m.insert({"banana", 3});
m["apple"]++;                    // now 6

// SAFE existence check — operator[] on absent key CREATES it with default value!
if (m.find("cherry") == m.end()) cout << "not found";
if (m.count("cherry") == 0) cout << "not found";     // cleaner

m.erase("banana");

for (auto &[key, val] : m) cout << key << ":" << val << "\n"; // sorted by key

map<int,int> freq;
for (int x : arr) freq[x]++;      // classic frequency counting pattern

auto it = m.lower_bound("banana"); // first key >= "banana"
```

**Common Mistakes:**
- **THE #1 map bug:** `if (m["key"] > 0)` on a non-existent key silently inserts `"key": 0` into the map (operator[] default-constructs). Use `m.count()` or `m.find()` for read-only existence checks.
- Iterating a `map` expecting insertion order — `map` iterates in **sorted key order**, not insertion order (use a `vector<pair>` alongside, or track order separately, if insertion order matters).
- Comparing `map<string,int>` custom key structs without providing `operator<` → compile error.

**Interview Tip:** `unordered_map` is O(1) average but `map` gives sorted order "for free" — explicitly justify your choice between them in interviews.

---

### 3.9 unordered_set / unordered_map

**Concept:** Hash-table backed — average O(1) insert/find/erase, but **O(n) worst case** (hash collisions/adversarial input, and notoriously exploitable on Codeforces via anti-hash tests).

```cpp
unordered_map<int,int> um;
um[5] = 10;
um.reserve(100000);              // pre-allocate buckets — reduces rehashing cost
if (um.find(5) != um.end()) { /* found */ }

unordered_set<int> us;
us.insert(5);
us.count(5); // 1 or 0
```

**Common Mistakes:**
- **Codeforces anti-hash attack:** using `unordered_map<int,...>` with default hash on CF can be deliberately TLE'd by adversarial test data exploiting the known hash function. Fix: use a custom hash (splitmix64-based) — see Section 42 "Custom Hash".
- Assuming O(1) always — worst case is O(n) per operation under collisions.
- No guaranteed iteration order — never rely on `unordered_map` order for output.
- Iterator invalidation on rehash after many inserts — don't hold iterators across insertions.

**When to use which (decision table):**

| Need | Container |
|---|---|
| Sorted iteration required | `map` / `set` |
| Fastest average lookup, order doesn't matter, trusted input | `unordered_map` / `unordered_set` |
| Codeforces / adversarial input | `map`/`set`, or `unordered_map` + custom hash |
| Duplicate keys/values allowed | `multimap` / `multiset` |
| Need k-th order statistic | `set` + GNU PBDS ordered_set |

---

*End of Part 1. Next up (Part 2): Algorithms Library (sort, permutations, set operations, accumulate family), Bit Manipulation, Prefix Sum, Difference Array, Sliding Window, Two Pointer, Binary Search — with the same depth. Just say "continue".*
