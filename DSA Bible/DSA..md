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

*End of Part 1.*

---

## 4. Algorithms Library (`<algorithm>`, `<numeric>`)

**Concept:** Header-provided generic algorithms operating on iterator ranges `[first, last)`. Knowing these cold saves you from hand-writing O(n) loops that already exist, battle-tested, in the standard library.

### 4.1 sort / stable_sort / reverse / rotate

```cpp
vector<int> v = {5,3,1,4,2};

sort(v.begin(), v.end());                     // ascending, O(n log n), NOT stable (introsort)
sort(v.begin(), v.end(), greater<int>());      // descending
stable_sort(v.begin(), v.end(), cmp);          // O(n log n), preserves relative order of equals — merge sort based

reverse(v.begin(), v.end());                   // O(n)

rotate(v.begin(), v.begin()+2, v.end());       // left-rotate by 2: [5,3,1,4,2] -> [1,4,2,5,3]
```

**Common Mistakes:**
- Using `sort` when order of equal elements matters (e.g. sorting jobs by deadline, then need original order preserved among ties) → use `stable_sort`.
- Custom comparator that isn't a strict weak ordering (e.g. using `<=` instead of `<`) → **undefined behavior**, can crash or infinite loop in `sort`.
- `rotate(first, middle, last)` — the *middle* argument becomes the *new first* element. Easy to mix up direction.

### 4.2 next_permutation / prev_permutation

**Concept:** Generates the lexicographically next/previous permutation in-place. O(n) per call. Used to brute-force all permutations of size ≤ ~10.

```cpp
vector<int> v = {1,2,3};
do {
    for (int x : v) cout << x << " ";
    cout << "\n";
} while (next_permutation(v.begin(), v.end()));
// Output: 123 132 213 231 312 321 (all 6 = 3! permutations)
```

**Common Mistakes:**
- Vector must be **sorted ascending** first to enumerate ALL permutations from the start — else you only get permutations from the current one onward.
- `next_permutation` returns `false` and wraps to the sorted (ascending) sequence when called on the last (descending) permutation — infinite loop risk if not paired with a `do-while` or checked properly.

### 4.3 Binary Search Family: lower_bound, upper_bound, binary_search

Already covered in 3.1 for vectors — same signatures apply to any sorted random-access range, arrays, and `set`/`map` (as member functions there, O(log n) native vs O(log n) via algorithm header but O(n) to advance iterators on non-random-access containers — so always prefer the **member function** `s.lower_bound()` over `std::lower_bound(s.begin(), s.end())` for `set`/`map`).

```cpp
int arr[] = {1,3,3,5,7,9};
int n = 6;
bool found = binary_search(arr, arr+n, 5);              // true
int firstIdx = lower_bound(arr, arr+n, 3) - arr;          // 1
int lastIdx  = upper_bound(arr, arr+n, 3) - arr - 1;      // 2
int cntOf3   = upper_bound(arr,arr+n,3) - lower_bound(arr,arr+n,3); // 2
```

### 4.4 min / max / min_element / max_element

```cpp
int a = min(3, 5);                    // 3
int b = max({1, 7, 3, 9, 2});         // 9 (initializer list overload)

vector<int> v = {4,1,7,3};
auto it = min_element(v.begin(), v.end());   // iterator to 1
int mnIdx = min_element(v.begin(), v.end()) - v.begin(); // index of min
int mx = *max_element(v.begin(), v.end());   // 7
```

**Common Mistake:** Forgetting to dereference `*min_element(...)` — the function returns an **iterator**, not the value.

### 4.5 accumulate / count / count_if / find / find_if

```cpp
vector<int> v = {1,2,3,4,5};
int sum = accumulate(v.begin(), v.end(), 0);            // 15
long long sum2 = accumulate(v.begin(), v.end(), 0LL);    // use 0LL to avoid int overflow!
int product = accumulate(v.begin(), v.end(), 1, multiplies<int>()); // 120

int cnt = count(v.begin(), v.end(), 3);                          // 1
int cntEven = count_if(v.begin(), v.end(), [](int x){return x%2==0;}); // 2

auto it = find(v.begin(), v.end(), 3);                            // iterator to 3
auto it2 = find_if(v.begin(), v.end(), [](int x){return x>3;});   // iterator to 4
bool exists = (find(v.begin(),v.end(),10) != v.end());
```

**Common Mistake:** `accumulate(v.begin(), v.end(), 0)` with `int` initial value silently overflows for large sums — **always seed with `0LL`** when the sum could exceed `2^31`.

### 4.6 all_of / any_of / none_of

```cpp
bool allPos = all_of(v.begin(), v.end(), [](int x){return x>0;});
bool anyNeg = any_of(v.begin(), v.end(), [](int x){return x<0;});
bool noneZero = none_of(v.begin(), v.end(), [](int x){return x==0;});
```

### 4.7 remove / unique / erase-remove idiom

```cpp
vector<int> v = {1,2,2,3,3,3,4};
// remove all 3s (moves them to end, returns new logical end — does NOT resize!)
v.erase(remove(v.begin(), v.end(), 3), v.end());   // v = {1,2,2,4}

// unique — removes CONSECUTIVE duplicates only, vector must be sorted first for full dedup
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());       // v = {1,2,4}
```

**Common Mistake:** Calling `unique()` on an unsorted vector only removes *adjacent* duplicates, not all duplicates — classic bug. Always `sort` before `unique` if full deduplication is intended.

### 4.8 merge / set_union / set_intersection / set_difference

**Precondition:** both input ranges must be sorted.

```cpp
vector<int> a = {1,3,5,7}, b = {2,3,5,9}, result;

merge(a.begin(),a.end(), b.begin(),b.end(), back_inserter(result));
// result = {1,2,3,3,5,5,7,9}  (merges keeping duplicates)

result.clear();
set_union(a.begin(),a.end(), b.begin(),b.end(), back_inserter(result));
// result = {1,2,3,5,7,9} (union, no duplicates)

result.clear();
set_intersection(a.begin(),a.end(), b.begin(),b.end(), back_inserter(result));
// result = {3,5}

result.clear();
set_difference(a.begin(),a.end(), b.begin(),b.end(), back_inserter(result));
// result = {1,7}  (elements in a but NOT in b)
```

### 4.9 transform / fill / iota / partial_sum / adjacent_difference

```cpp
vector<int> v = {1,2,3}, out(3);
transform(v.begin(), v.end(), out.begin(), [](int x){ return x*x; }); // out = {1,4,9}

fill(v.begin(), v.end(), 0);                 // all zeros
vector<int> idx(5); iota(idx.begin(), idx.end(), 0); // {0,1,2,3,4}
iota(idx.begin(), idx.end(), 10);             // {10,11,12,13,14}

vector<int> arr = {1,2,3,4};
vector<int> pre(4);
partial_sum(arr.begin(), arr.end(), pre.begin()); // {1,3,6,10} — running prefix sum!

vector<int> diff(4);
adjacent_difference(arr.begin(), arr.end(), diff.begin()); // {1,1,1,1}
```

**CP Trick:** `partial_sum` gives you prefix sums in **one line** — no need to hand-roll the loop in a hurry.

### 4.10 gcd / lcm / pow

```cpp
int g = __gcd(12, 18);          // 6 — old GCC builtin, works pre-C++17 too
int g2 = gcd(12, 18);           // 6 — <numeric>, C++17 standard
long long l = lcm(4, 6);        // 12 — C++17, (a/gcd(a,b))*b to avoid overflow
double p = pow(2, 10);          // 1024.0 — returns DOUBLE, precision risk for large ints!

// Never use pow() for integer exponentiation in CP — use fast power (Section 42)
long long fastPow(long long base, long long exp, long long mod) {
    long long res = 1; base %= mod;
    while (exp > 0) {
        if (exp & 1) res = res * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return res;
}
```

**Common Mistake:** Using `pow(2, 30)` and assigning to `int` — floating point rounding can give `1073741823` instead of `1073741824`. **Never use `pow()` for integer results** — write bit-shift or fast exponentiation instead.

---

## 5. Bit Manipulation

**Concept:** Directly manipulate binary representation for O(1)/O(log n) tricks — subsets, masks, parity, fast arithmetic. Extremely high ROI topic for CP.

### 5.1 Core Operators

| Op | Symbol | Meaning |
|---|---|---|
| AND | `&` | 1 if both bits are 1 |
| OR | `\|` | 1 if either bit is 1 |
| XOR | `^` | 1 if bits differ |
| NOT | `~` | flips all bits |
| Left shift | `<<` | multiply by 2^k |
| Right shift | `>>` | divide by 2^k (floor) |

```cpp
int x = 5;             // 0b0101
int y = 3;             // 0b0011
cout << (x & y);        // 1  (0b0001)
cout << (x | y);        // 7  (0b0111)
cout << (x ^ y);        // 6  (0b0110)
cout << (~x);            // -6 (two's complement, flips ALL 32 bits)
cout << (x << 1);        // 10 (0b1010)
cout << (x >> 1);        // 2  (0b0010, floor division)
```

### 5.2 Common Bit Tricks

```cpp
// Check if bit i is set
bool isSet = (x >> i) & 1;

// Set bit i
x |= (1 << i);

// Clear (unset) bit i
x &= ~(1 << i);

// Toggle bit i
x ^= (1 << i);

// Check if x is a power of 2 (and x != 0)
bool isPow2 = x > 0 && (x & (x-1)) == 0;

// Get lowest set bit
int lowBit = x & (-x);

// Remove lowest set bit
int removed = x & (x-1);

// Count set bits (popcount)
int cnt = __builtin_popcount(x);        // for int
int cntll = __builtin_popcountll(x);    // for long long

// Count trailing/leading zeros (undefined if x==0!)
int tz = __builtin_ctz(x);      // trailing zeros
int lz = __builtin_clz(x);      // leading zeros

// XOR swap (no temp variable)
a ^= b; b ^= a; a ^= b;

// Check if two numbers have opposite signs
bool oppositeSign = (a ^ b) < 0;
```

### 5.3 Subset / Mask Enumeration

```cpp
// Enumerate all 2^n subsets of n elements
int n = 3;
for (int mask = 0; mask < (1<<n); mask++) {
    vector<int> subset;
    for (int i = 0; i < n; i++)
        if (mask & (1<<i)) subset.push_back(i);
    // process subset
}

// Enumerate all submasks of a given mask (useful in SOS DP)
int mask = 0b1011;
for (int sub = mask; ; sub = (sub-1) & mask) {
    // process sub
    if (sub == 0) break;
}
```

**Dry Run — submask enumeration for mask = 0b101 (5):**
```
sub = 101 (5)  -> process
sub = (101-1)&101 = 100&101 = 100 (4) -> process
sub = (100-1)&101 = 011&101 = 001 (1) -> process
sub = (001-1)&101 = 000&101 = 000 (0) -> process, then break
Submasks of 5: {5, 4, 1, 0}
```

**Common Mistakes:**
- `__builtin_ctz(0)` / `__builtin_clz(0)` → **undefined behavior**, always guard `if (x != 0)` first.
- `1 << i` overflows `int` for `i >= 31` — use `1LL << i` for large shifts.
- `~x` on unsigned types behaves differently than signed — be careful when mixing.
- Forgetting operator precedence: `x & 1 == 0` parses as `x & (1==0)` due to `==` binding tighter than `&` — **always parenthesize**: `(x & 1) == 0`.

**Interview Tip:** "Count set bits", "single number (XOR trick)", and "power of two check" are extremely common bit-manipulation interview questions — know all three cold.

---

## 6. Prefix Sum

**Concept:** Precompute cumulative sums so any range-sum query becomes O(1) after O(n) preprocessing. Foundational for range-query problems.

```cpp
vector<int> arr = {3, 1, 4, 1, 5, 9};
int n = arr.size();
vector<long long> prefix(n+1, 0);   // prefix[i] = sum of arr[0..i-1]
for (int i = 0; i < n; i++)
    prefix[i+1] = prefix[i] + arr[i];

// Range sum query [l, r] inclusive, 0-indexed
auto rangeSum = [&](int l, int r) {
    return prefix[r+1] - prefix[l];
};
cout << rangeSum(1, 3);  // arr[1]+arr[2]+arr[3] = 1+4+1 = 6
```

**Dry Run:**
```
arr     = [3, 1, 4, 1, 5, 9]
prefix  = [0, 3, 4, 8, 9, 14, 23]
rangeSum(1,3) = prefix[4] - prefix[1] = 9 - 3 = 6 ✓
```

**2D Prefix Sum (for matrix range-sum queries):**
```cpp
int n=3, m=3;
vector<vector<int>> grid = {{1,2,3},{4,5,6},{7,8,9}};
vector<vector<long long>> pre(n+1, vector<long long>(m+1, 0));
for (int i=0;i<n;i++)
    for (int j=0;j<m;j++)
        pre[i+1][j+1] = pre[i][j+1] + pre[i+1][j] - pre[i][j] + grid[i][j];

// Sum of submatrix (r1,c1) to (r2,c2) inclusive
auto sum2D = [&](int r1,int c1,int r2,int c2) {
    return pre[r2+1][c2+1] - pre[r1][c2+1] - pre[r2+1][c1] + pre[r1][c1];
};
```

**Common Mistakes:**
- Off-by-one: using `prefix[i]` = sum up to index `i` **inclusive** vs `prefix[i+1]` = sum of first `i` elements — pick one convention and stick to it (this handbook uses the `n+1` size, 1-indexed-prefix convention to avoid negative-index checks).
- Forgetting `long long` for prefix sums when array values are large — sums grow fast.
- 2D prefix sum inclusion-exclusion sign errors — draw it out: `pre[r2+1][c2+1] - pre[r1][c2+1] - pre[r2+1][c1] + pre[r1][c1]` (add back the double-subtracted corner).

**Contest Trick:** Prefix XOR works the same way (`prefixXor[i+1] = prefixXor[i] ^ arr[i]`) for range-XOR queries in O(1).

---

## 7. Difference Array

**Concept:** The inverse of prefix sum — apply O(1) range updates, then recover final array via one O(n) prefix-sum pass. Essential for "many range increments, then read final array" problems.

```cpp
int n = 6;
vector<long long> diff(n+1, 0);

// range update: add `val` to arr[l..r] inclusive
auto rangeUpdate = [&](int l, int r, long long val) {
    diff[l] += val;
    diff[r+1] -= val;
};

rangeUpdate(1, 3, 5);   // add 5 to indices 1,2,3
rangeUpdate(0, 5, 2);   // add 2 to indices 0..5

// Reconstruct final array via prefix sum of diff
vector<long long> result(n);
long long running = 0;
for (int i = 0; i < n; i++) {
    running += diff[i];
    result[i] = running;
}
// result = [2, 7, 7, 7, 2, 2]
```

**Dry Run:**
```
diff after updates: diff[0]+=2, diff[1]+=5, diff[4]-=5, diff[6]-=2
diff = [2, 5, 0, 0, -5, 0, -2]
running sum: 2, 7, 7, 7, 2, 2  -> matches result ✓
```

**Common Mistakes:**
- Forgetting the `diff[r+1] -= val` step (only doing `diff[l] += val`) → the increment "leaks" past index `r` into all subsequent indices.
- Array size must be `n+1` to safely handle `r == n-1` → `r+1 == n` without out-of-bounds access.
- Difference array only works for **offline** batch updates followed by a single reconstruction — not for interleaved "update then query" patterns (use a Segment Tree/Fenwick Tree with range-update for that — Sections 34/35).

---

## 8. Sliding Window

**Concept:** Maintain a window `[left, right]` over an array/string, expanding/shrinking based on a condition — turns many O(n²) brute-force problems into O(n).

### 8.1 Fixed-Size Window

```cpp
// Max sum of any subarray of size k
long long maxSumFixed(vector<int>& arr, int k) {
    long long windowSum = 0, best = LLONG_MIN;
    for (int i = 0; i < arr.size(); i++) {
        windowSum += arr[i];
        if (i >= k-1) {
            best = max(best, windowSum);
            windowSum -= arr[i-k+1];   // remove leftmost element of window
        }
    }
    return best;
}
```

### 8.2 Variable-Size Window (condition-based)

```cpp
// Longest substring with at most k distinct characters
int longestKDistinct(string s, int k) {
    unordered_map<char,int> freq;
    int left = 0, best = 0;
    for (int right = 0; right < s.size(); right++) {
        freq[s[right]]++;
        while (freq.size() > k) {              // shrink window until valid
            freq[s[left]]--;
            if (freq[s[left]] == 0) freq.erase(s[left]);
            left++;
        }
        best = max(best, right - left + 1);
    }
    return best;
}
```

**Dry Run — s = "eceba", k = 2:**
```
right=0 'e': freq={e:1}          window="e"     best=1
right=1 'c': freq={e:1,c:1}      window="ec"    best=2
right=2 'e': freq={e:2,c:1}      window="ece"   best=3
right=3 'b': freq={e:2,c:1,b:1} >k=2, shrink:
   remove s[0]='e': freq={e:1,c:1,b:1}, still >2
   remove s[1]='c': freq={e:1,b:1}, size=2 OK, left=2
   window="eb" (indices 2..3)    best=3 (unchanged)
right=4 'a': freq={e:1,b:1,a:1} >2, shrink:
   remove s[2]='e': freq={b:1,a:1}, left=3
   window="ba"                   best=3 (unchanged)
Answer: 3 ("ece")
```

**Common Mistakes:**
- Shrinking with `if` instead of `while` — condition may need multiple shrink steps in a row.
- Forgetting to erase a key from the frequency map when its count hits 0 → `freq.size()` overcounts distinct characters.
- Off-by-one in window length: `right - left + 1`, not `right - left`.

**Interview Tip:** Sliding window signals: "longest/shortest substring/subarray with condition X" — almost always O(n) two-pointer/sliding-window solvable; jumping straight to O(n²) brute force is a red flag in interviews.

---

## 9. Two Pointer

**Concept:** Two indices moving through data (often from opposite ends, or both forward at different speeds) to avoid nested loops. Requires sorted data or a monotonic property in most variants.

### 9.1 Opposite-Ends Pattern (sorted array)

```cpp
// Two Sum in a SORTED array — return indices (or -1,-1)
pair<int,int> twoSumSorted(vector<int>& arr, int target) {
    int l = 0, r = arr.size()-1;
    while (l < r) {
        long long sum = arr[l] + arr[r];
        if (sum == target) return {l, r};
        else if (sum < target) l++;
        else r--;
    }
    return {-1, -1};
}
```

### 9.2 Fast-Slow Pointer (cycle detection)

```cpp
// Floyd's cycle detection (also used for linked lists — Section 12)
bool hasCycle(vector<int>& next, int start) {
    int slow = start, fast = start;
    do {
        slow = next[slow];
        fast = next[next[fast]];
    } while (slow != fast);
    return true; // simplistic; real version needs a "no cycle" exit condition
}
```

### 9.3 Same-Direction Pointer (remove duplicates in-place)

```cpp
// Remove duplicates from sorted array in-place, return new length
int removeDuplicates(vector<int>& arr) {
    if (arr.empty()) return 0;
    int slow = 0;
    for (int fast = 1; fast < arr.size(); fast++) {
        if (arr[fast] != arr[slow]) {
            slow++;
            arr[slow] = arr[fast];
        }
    }
    return slow + 1;
}
```

**Dry Run — removeDuplicates on [1,1,2,2,3]:**
```
slow=0, fast=1: arr[1]=1==arr[0]=1, skip
fast=2: arr[2]=2 != arr[0]=1 -> slow=1, arr[1]=2 -> [1,2,2,2,3]
fast=3: arr[3]=2==arr[1]=2, skip
fast=4: arr[4]=3 != arr[1]=2 -> slow=2, arr[2]=3 -> [1,2,3,2,3]
Return slow+1 = 3 -> first 3 elements [1,2,3] are the deduped result
```

**Common Mistakes:**
- Applying opposite-ends two pointer on **unsorted** data without sorting first (when the problem allows reordering) — breaks the monotonic shrink logic.
- Off-by-one when converging pointers: `l < r` vs `l <= r` changes whether single-element windows are considered.
- Confusing "two pointer" with "sliding window" — two pointer often has *both* pointers moving independently (not just right expanding and left catching up); pick the right mental model per problem.

**Interview Tip:** "Container With Most Water", "3Sum", "Trapping Rain Water" — all classic two-pointer interview questions; mention the O(n²)→O(n) reduction explicitly to show algorithmic awareness.

---

## 10. Binary Search

**Concept:** Halve the search space each step on a **monotonic** predicate — O(log n). Beyond "find x in sorted array," the real power is binary-searching on the *answer* itself.

### 10.1 Classic Binary Search

```cpp
int binarySearch(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size()-1;
    while (lo <= hi) {
        int mid = lo + (hi-lo)/2;    // avoids overflow vs (lo+hi)/2
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid+1;
        else hi = mid-1;
    }
    return -1;
}
```

### 10.2 Binary Search on Answer (the real CP superpower)

**Concept:** When the answer space is monotonic (`f(x)` is true for all `x ≥ threshold`, false otherwise, or vice versa), binary search the threshold directly instead of the array.

```cpp
// Example: minimum "max allowed capacity" to ship all packages within `days`
bool canShip(vector<int>& weights, int days, int capacity) {
    int daysNeeded = 1, curLoad = 0;
    for (int w : weights) {
        if (curLoad + w > capacity) { daysNeeded++; curLoad = 0; }
        curLoad += w;
    }
    return daysNeeded <= days;
}

int shipWithinDays(vector<int>& weights, int days) {
    int lo = *max_element(weights.begin(), weights.end()); // capacity must fit largest package
    int hi = accumulate(weights.begin(), weights.end(), 0);
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (canShip(weights, days, mid)) hi = mid;   // mid works, try smaller
        else lo = mid+1;                              // mid too small, need bigger
    }
    return lo;
}
```

### 10.3 lower_bound / upper_bound style manual implementation

```cpp
// First index where arr[idx] >= target (manual lower_bound)
int lowerBoundManual(vector<int>& arr, int target) {
    int lo = 0, hi = arr.size();  // NOTE: hi = size(), not size()-1, for this template
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if (arr[mid] < target) lo = mid+1;
        else hi = mid;
    }
    return lo;  // could equal arr.size() if all elements < target
}
```

**Common Mistakes:**
- `(lo+hi)/2` overflow when `lo, hi` are near `INT_MAX` — always use `lo + (hi-lo)/2`.
- Infinite loop from wrong bracket update: `lo = mid` instead of `lo = mid+1` (or vice versa) when `mid` is already excluded from further search.
- Mixing `hi = arr.size()-1` (closed interval) template with `hi = mid` (half-open interval) update rules — the two templates use **different** loop conditions (`lo<=hi` vs `lo<hi`) and must not be mixed.
- Binary searching on a non-monotonic predicate → silently wrong answer with no crash (hardest bug class to catch).

**Interview Tip:** Whenever you see "minimize the maximum" or "maximize the minimum" phrasing, think **binary search on the answer** immediately — it's a very strong signal pattern.

---

## 11. Sorting

**Concept:** Beyond `std::sort`, know how the major algorithms work internally — interviewers frequently ask you to implement one from scratch, and understanding stability/complexity trade-offs matters for choosing the right one.

### 11.1 Complexity & Stability Reference

| Algorithm | Best | Average | Worst | Space | Stable? |
|---|---|---|---|---|---|
| Bubble Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Selection Sort | O(n²) | O(n²) | O(n²) | O(1) | No |
| Insertion Sort | O(n) | O(n²) | O(n²) | O(1) | Yes |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) | No |
| Heap Sort | O(n log n) | O(n log n) | O(n log n) | O(1) | No |
| `std::sort` (introsort) | O(n log n) | O(n log n) | O(n log n) | O(log n) | No |
| `std::stable_sort` | O(n log n) | O(n log n) | O(n log n) | O(n) | Yes |

### 11.2 Merge Sort (implement-from-scratch template)

```cpp
void merge(vector<int>& arr, int l, int mid, int r) {
    vector<int> temp;
    int i = l, j = mid+1;
    while (i <= mid && j <= r) {
        if (arr[i] <= arr[j]) temp.push_back(arr[i++]);
        else temp.push_back(arr[j++]);
    }
    while (i <= mid) temp.push_back(arr[i++]);
    while (j <= r) temp.push_back(arr[j++]);
    for (int k = l; k <= r; k++) arr[k] = temp[k-l];
}

void mergeSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);
    merge(arr, l, mid, r);
}
```

### 11.3 Quick Sort (Lomuto partition)

```cpp
int partition(vector<int>& arr, int l, int r) {
    int pivot = arr[r], i = l-1;
    for (int j = l; j < r; j++)
        if (arr[j] < pivot) swap(arr[++i], arr[j]);
    swap(arr[i+1], arr[r]);
    return i+1;
}

void quickSort(vector<int>& arr, int l, int r) {
    if (l >= r) return;
    int p = partition(arr, l, r);
    quickSort(arr, l, p-1);
    quickSort(arr, p+1, r);
}
```

**Common Mistakes:**
- Quick Sort worst case O(n²) on already-sorted or adversarial input if pivot is always first/last element — mitigate with random pivot selection.
- Merge Sort needs O(n) extra space per merge call — total O(n) auxiliary (not O(n log n), since temp arrays aren't all alive simultaneously if implemented carefully).
- Forgetting merge sort/quicksort base case `l >= r` → infinite recursion or index-out-of-bounds.
- Using `std::sort` when problem explicitly requires "count inversions during sort" or a stable, custom in-place implementation — sometimes the interviewer wants to see you implement it, not call the STL.

**CP Trick:** Counting inversions is a natural byproduct of merge sort — count cross-pairs during the merge step (`i <= mid && j <= r && arr[i] > arr[j]` contributes `mid-i+1` inversions).

---

*End of Part 2.*

---

## 12. Linked List

**Concept:** Nodes connected via pointers instead of contiguous memory — O(1) insert/delete at known position, O(n) access. Core interview topic for pointer manipulation.

### 12.1 Node Definition & Basic Operations

```cpp
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// Insert at head — O(1)
ListNode* insertHead(ListNode* head, int val) {
    ListNode* node = new ListNode(val);
    node->next = head;
    return node;
}

// Insert at tail — O(n)
void insertTail(ListNode* head, int val) {
    ListNode* node = new ListNode(val);
    if (!head) { head = node; return; }
    ListNode* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

// Delete a node by value — O(n)
ListNode* deleteVal(ListNode* head, int val) {
    if (!head) return nullptr;
    if (head->val == val) return head->next;   // delete head
    ListNode* cur = head;
    while (cur->next && cur->next->val != val) cur = cur->next;
    if (cur->next) cur->next = cur->next->next;
    return head;
}
```

### 12.2 Reverse a Linked List (iterative — the #1 asked LL question)

```cpp
ListNode* reverseList(ListNode* head) {
    ListNode* prev = nullptr;
    ListNode* cur = head;
    while (cur) {
        ListNode* nxt = cur->next;
        cur->next = prev;
        prev = cur;
        cur = nxt;
    }
    return prev;  // new head
}
```

**Dry Run — reverse 1->2->3->nullptr:**
```
prev=null, cur=1
step1: nxt=2, 1->next=null, prev=1, cur=2      list so far: 1->null
step2: nxt=3, 2->next=1,    prev=2, cur=3      list so far: 2->1->null
step3: nxt=null,3->next=2,  prev=3, cur=null   list so far: 3->2->1->null
Return prev = 3 (new head). Result: 3->2->1
```

### 12.3 Detect Cycle (Floyd's Tortoise and Hare)

```cpp
bool hasCycle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) return true;
    }
    return false;
}

// Find the START of the cycle
ListNode* detectCycleStart(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next; fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            while (slow != fast) { slow = slow->next; fast = fast->next; }
            return slow;
        }
    }
    return nullptr;
}
```

### 12.4 Merge Two Sorted Lists / Find Middle

```cpp
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    while (l1 && l2) {
        if (l1->val <= l2->val) { tail->next = l1; l1 = l1->next; }
        else { tail->next = l2; l2 = l2->next; }
        tail = tail->next;
    }
    tail->next = l1 ? l1 : l2;
    return dummy.next;
}

// Find middle node (slow-fast pointer)
ListNode* findMiddle(ListNode* head) {
    ListNode *slow = head, *fast = head;
    while (fast && fast->next) { slow = slow->next; fast = fast->next->next; }
    return slow;  // for even length, returns the SECOND middle node
}
```

**Common Mistakes:**
- Memory leaks: `delete`-ing nodes is required in real C++ (not GC'd like Java/Python) — always `delete node;` after unlinking if not using smart pointers. In interviews this is often overlooked but shows engineering maturity to mention.
- Losing the head pointer while traversing — always keep `head` untouched, traverse with a separate `cur` pointer.
- Off-by-one in "find middle": clarify with interviewer whether "middle of even-length list" should be the 1st or 2nd middle node.
- Forgetting `dummy` node trick for merge/insert-at-head-heavy operations — makes edge cases (empty list, inserting before head) disappear.
- Null pointer dereference: always check `node != nullptr` before `node->next`.

**Interview Tip:** "Reverse a linked list", "detect cycle", "merge k sorted lists", "remove nth node from end" (fast pointer offset by n) are the four most-asked LL questions — practice all four blind.

---

## 13–15. Stack, Queue, Deque — Implementation Patterns

*(STL syntax already covered in 3.4/3.5. This section covers deque plus classic usage patterns.)*

### 15.1 deque (double-ended queue)

**Concept:** O(1) push/pop at **both** ends, O(1) random access — implemented as a chunked array, not a linked list.

```cpp
deque<int> dq;
dq.push_back(1); dq.push_front(2);   // dq = {2, 1}
dq.pop_back(); dq.pop_front();
int f = dq.front(), b = dq.back();
int x = dq[0];                        // O(1) random access, unlike list
```

### 13.1 Stack — Implement Using Two Queues / Array (interview classic)

```cpp
class MyStack {
    vector<int> data;
public:
    void push(int x) { data.push_back(x); }
    void pop() { data.pop_back(); }
    int top() { return data.back(); }
    bool empty() { return data.empty(); }
};
```

### 14.1 Queue — Implement Using a Stack (or two stacks for O(1) amortized)

```cpp
class MyQueue {
    stack<int> in, out;
    void transfer() {
        if (out.empty()) while (!in.empty()) { out.push(in.top()); in.pop(); }
    }
public:
    void push(int x) { in.push(x); }
    int pop() { transfer(); int v = out.top(); out.pop(); return v; }
    int peek() { transfer(); return out.top(); }
    bool empty() { return in.empty() && out.empty(); }
};
```

**Common Mistakes:**
- Two-stack queue: forgetting to only transfer when `out` is empty → breaks amortized O(1) (would become O(n) every call if transferred every time).
- Confusing `deque::at(i)` (bounds-checked, throws) with `deque[i]` (unchecked, UB on out-of-range).

---

## 16. Monotonic Stack

**Concept:** A stack kept strictly increasing or decreasing, used to solve "next greater/smaller element" family problems in O(n) total (each element pushed/popped once).

```cpp
// Next Greater Element for every index — O(n)
vector<int> nextGreaterElement(vector<int>& arr) {
    int n = arr.size();
    vector<int> result(n, -1);
    stack<int> st;              // stores INDICES, monotonic decreasing values
    for (int i = 0; i < n; i++) {
        while (!st.empty() && arr[st.top()] < arr[i]) {
            result[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return result;
}
```

**Dry Run — arr = [2,1,2,4,3]:**
```
i=0 (2): stack empty, push 0.        st=[0]
i=1 (1): arr[0]=2 !< 1, push 1.      st=[0,1]
i=2 (2): arr[1]=1<2 -> result[1]=2, pop. arr[0]=2 !<2, push 2. st=[0,2]
i=3 (4): arr[2]=2<4 -> result[2]=4, pop. arr[0]=2<4 -> result[0]=4, pop. push 3. st=[3]
i=4 (3): arr[3]=4 !<3, push 4.        st=[3,4]
End: result[3]=-1, result[4]=-1 (nothing popped for them)
Final result = [4, 2, 4, -1, -1]
```

**Classic Applications:**
- Next/previous greater/smaller element.
- **Largest Rectangle in Histogram** — monotonic increasing stack of indices; when a smaller bar appears, pop and compute area with popped bar as height.
- **Trapping Rain Water** (stack-based variant).
- **Stock Span Problem.**

**Common Mistakes:**
- Storing values instead of **indices** on the stack when you need positions to compute widths/distances (e.g., histogram problem needs index differences).
- Wrong monotonic direction: "next greater" needs a decreasing stack; "next smaller" needs an increasing stack — mixing these up gives silently wrong answers.
- Off-by-one when computing width in histogram problem: width = `i - st.top() - 1` after popping, needs careful boundary handling when stack becomes empty (means width extends to index 0).

---

## 17. Monotonic Queue

**Concept:** A deque kept monotonic to answer "max/min in every sliding window of size k" in O(n) total, instead of O(n·k) or O(n log k) with a heap.

```cpp
// Sliding Window Maximum — O(n)
vector<int> maxSlidingWindow(vector<int>& arr, int k) {
    deque<int> dq;   // stores indices, values monotonically DECREASING
    vector<int> result;
    for (int i = 0; i < arr.size(); i++) {
        // remove indices out of window
        while (!dq.empty() && dq.front() <= i-k) dq.pop_front();
        // maintain decreasing order — pop smaller elements from back
        while (!dq.empty() && arr[dq.back()] < arr[i]) dq.pop_back();
        dq.push_back(i);
        if (i >= k-1) result.push_back(arr[dq.front()]);
    }
    return result;
}
```

**Dry Run — arr = [1,3,-1,-3,5,3,6,7], k=3:**
```
i=0(1): dq=[0]
i=1(3): arr[0]=1<3, pop 0. dq=[1]
i=2(-1): -1<3 not popped. dq=[1,2]. i>=2: result=[3]
i=3(-3): dq=[1,2,3]. front=1 in range(3-3=0,ok). result=[3,3]
i=4(5): pop 3(-3<5),pop2(-1<5),pop1(3<5). dq=[4]. result=[3,3,5]
i=5(3): dq=[4,5]. front=4, i-k=2,4>2 ok. result=[3,3,5,5]
i=6(6): pop5(3<6),pop4(5<6). dq=[6]. result=[...,6]
i=7(7): pop6(6<7). dq=[7]. result=[...,7]
Final: [3,3,5,5,6,7]
```

**Common Mistakes:**
- Removing out-of-window indices with `if` instead of `while` (rare, but can matter for k=1 edge cases) — usually `if` suffices here since only one element leaves per step, but always double check.
- Forgetting the window-boundary check `dq.front() <= i-k` uses **index** comparison, not value — a frequent source of bugs when adapting templates.
- Applying monotonic queue when a simple prefix/suffix max array would suffice — monotonic queue's power is specifically for **sliding** (both ends moving) windows.

---

## 18. Heap (Manual Implementation)

**Concept:** Binary heap stored in a flat array — parent at `i`, children at `2i+1` and `2i+2`. `priority_queue` (Section 3.6) is the STL heap; here's what's under the hood, often asked to implement in interviews.

```cpp
class MinHeap {
    vector<int> heap;
    void heapifyUp(int i) {
        while (i > 0 && heap[(i-1)/2] > heap[i]) {
            swap(heap[(i-1)/2], heap[i]);
            i = (i-1)/2;
        }
    }
    void heapifyDown(int i) {
        int n = heap.size();
        while (true) {
            int smallest = i, l = 2*i+1, r = 2*i+2;
            if (l < n && heap[l] < heap[smallest]) smallest = l;
            if (r < n && heap[r] < heap[smallest]) smallest = r;
            if (smallest == i) break;
            swap(heap[i], heap[smallest]);
            i = smallest;
        }
    }
public:
    void push(int val) {
        heap.push_back(val);
        heapifyUp(heap.size()-1);
    }
    int top() { return heap[0]; }
    void pop() {
        heap[0] = heap.back();
        heap.pop_back();
        if (!heap.empty()) heapifyDown(0);
    }
    bool empty() { return heap.empty(); }
};
```

**Also usable:** raw STL heap functions on a vector:
```cpp
vector<int> v = {5,1,3,8,2};
make_heap(v.begin(), v.end());              // O(n), max-heap by default
push_heap(v.begin(), v.end());              // after v.push_back(x)
pop_heap(v.begin(), v.end());                // moves max to v.back(), then v.pop_back()
```

**Common Mistakes:**
- Off-by-one in parent/child index formulas — memorize: parent=`(i-1)/2`, left=`2i+1`, right=`2i+2` (0-indexed array).
- `pop_heap` doesn't actually remove the element — it moves the max to the end; you must call `v.pop_back()` yourself afterward.
- Heapify complexity confusion: building a heap from `n` elements one-by-one via `push` is O(n log n); `make_heap` on an existing array is O(n) (tighter bound via amortized analysis).

**Interview Tip:** "Implement a min-heap from scratch" and "Kth largest element in a stream" (maintain a min-heap of size k) are top heap interview questions.

---

## 19. Hashing

**Concept:** Map data to fixed-size buckets for O(1) average lookup. Beyond `unordered_map` (Section 3.9), know **string hashing** for substring comparison problems.

### 19.1 Polynomial String Hashing

```cpp
using ull = unsigned long long;
const ull BASE = 131, MOD = 1e9+7;

vector<ull> computeHashPrefix(string& s) {
    int n = s.size();
    vector<ull> hashPre(n+1, 0), power(n+1, 1);
    for (int i = 0; i < n; i++) {
        power[i+1] = (power[i] * BASE) % MOD;
        hashPre[i+1] = (hashPre[i] * BASE + s[i]) % MOD;
    }
    return hashPre; // pair this with `power` to get substring hash in O(1)
}

// Hash of substring s[l..r] inclusive, given precomputed hashPre & power
ull substrHash(vector<ull>& hashPre, vector<ull>& power, int l, int r) {
    ull res = (hashPre[r+1] - (hashPre[l] * power[r-l+1]) % MOD + MOD * MOD) % MOD;
    return res;
}
```

**Common Mistakes:**
- Single-hash collisions are exploitable (especially on Codeforces with adversarial tests) — use **double hashing** (two different bases/mods) for safety-critical problems.
- Negative modulo results in C++ (`(a - b) % mod` can be negative if `a < b`) — always add `MOD` before taking `% MOD` again.
- `unsigned long long` overflow wraps silently instead of throwing — intentional here for hashing, but dangerous if unintended elsewhere.

**CP Trick:** Custom hash to defeat Codeforces anti-unordered_map hacking:
```cpp
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
unordered_map<long long, int, custom_hash> safe_map;
```

---

## 20. String Algorithms

**Concept:** Pattern matching, palindromes, and substring problems — a huge chunk of both interview and CP strings questions.

### 20.1 KMP (Knuth-Morris-Pratt) Pattern Matching — O(n+m)

```cpp
vector<int> computeLPS(string& pat) {
    int m = pat.size();
    vector<int> lps(m, 0);
    int len = 0, i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) { lps[i++] = ++len; }
        else if (len) len = lps[len-1];
        else lps[i++] = 0;
    }
    return lps;
}

vector<int> KMPsearch(string& text, string& pat) {
    vector<int> lps = computeLPS(pat), matches;
    int n = text.size(), m = pat.size();
    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pat[j]) { i++; j++; }
        if (j == m) { matches.push_back(i-j); j = lps[j-1]; }
        else if (i < n && text[i] != pat[j]) {
            if (j) j = lps[j-1];
            else i++;
        }
    }
    return matches;
}
```

### 20.2 Palindrome Checks & Manacher's (longest palindromic substring, O(n))

```cpp
bool isPalindrome(string s) {
    int l = 0, r = s.size()-1;
    while (l < r) if (s[l++] != s[r--]) return false;
    return true;
}

// Expand-around-center — O(n^2) but simple, fine for n <= ~5000
string longestPalindrome(string s) {
    int n = s.size(), start = 0, maxLen = 0;
    auto expand = [&](int l, int r) {
        while (l >= 0 && r < n && s[l] == s[r]) { l--; r++; }
        if (r-l-1 > maxLen) { maxLen = r-l-1; start = l+1; }
    };
    for (int i = 0; i < n; i++) { expand(i,i); expand(i,i+1); } // odd & even centers
    return s.substr(start, maxLen);
}
```

### 20.3 Z-Algorithm (O(n) pattern matching alternative to KMP)

```cpp
vector<int> zFunction(string s) {
    int n = s.size();
    vector<int> z(n, 0);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r-i, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
        if (i+z[i] > r) { l = i; r = i+z[i]; }
    }
    return z;
}
// To search pattern P in text T: run Z on (P + '#' + T), z[i]==|P| marks a match
```

**Common Mistakes:**
- KMP: forgetting the LPS (failure function) preprocessing → degrades to naive O(nm).
- Manacher's algorithm is O(n) but has fiddly index transformations — the O(n²) expand-around-center is far less bug-prone and fine unless `n > ~10^4`.
- Off-by-one in substring extraction after finding palindrome bounds.
- Z-function: forgetting the separator character (`#`) between pattern and text when using Z for pattern matching — without it, matches can bleed across the boundary.

**Interview Tip:** Most string interview questions (valid anagram, longest palindromic substring, group anagrams) don't need KMP/Z — they need hashmap counting or O(n²) DP. Reach for KMP/Z only when asked for O(n+m) exact pattern search explicitly, or in CP.

---

## 21. Trie (Prefix Tree)

**Concept:** Tree where each path from root represents a string prefix — O(L) insert/search where L = string length, independent of how many strings are stored. Ideal for prefix queries, autocomplete, and word dictionaries.

```cpp
struct TrieNode {
    TrieNode* children[26] = {nullptr};
    bool isEnd = false;
};

class Trie {
    TrieNode* root;
public:
    Trie() { root = new TrieNode(); }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) node->children[idx] = new TrieNode();
            node = node->children[idx];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix) {
            int idx = c - 'a';
            if (!node->children[idx]) return false;
            node = node->children[idx];
        }
        return true;  // just needs to reach here, isEnd doesn't matter
    }
};
```

**Dry Run — insert("cat"), insert("car"), search("cat"), startsWith("ca"):**
```
insert("cat"): root -c-> node1 -a-> node2 -t-> node3(isEnd=true)
insert("car"): root -c-> node1 -a-> node2 -r-> node4(isEnd=true)
                          (node1, node2 REUSED from "cat" insertion)
search("cat"): traverse c->a->t, reach node3, isEnd=true -> return true
startsWith("ca"): traverse c->a, reach node2, node2 exists -> return true (isEnd irrelevant)
```

**Common Mistakes:**
- Confusing `search()` (must be a complete inserted word, checks `isEnd`) with `startsWith()` (just needs the path to exist, ignores `isEnd`) — swapping these is the most common Trie bug.
- Memory leak: 26 pointers per node adds up fast for large dictionaries — consider `unordered_map<char, TrieNode*>` for sparse alphabets (e.g., Unicode) at the cost of slightly slower access.
- Forgetting to handle the empty string edge case, or strings with characters outside `'a'-'z'` (index out of bounds on `children[c-'a']` for uppercase/digits/symbols).

**CP Trick — Binary Trie for XOR problems:** build a trie over the 30-bit binary representation of numbers to answer "maximum XOR pair" queries in O(n log(max_val)).

---

*End of Part 3.*

---

## 22. Recursion

**Concept:** Function calls itself on a smaller subproblem until a base case. Foundation of DFS, backtracking, divide-and-conquer, and DP.

```cpp
// Factorial — simplest recursion
long long factorial(int n) {
    if (n <= 1) return 1;               // base case
    return n * factorial(n-1);           // recursive case
}

// Recursion with multiple branches — Fibonacci (exponential without memo!)
int fib(int n) {
    if (n <= 1) return n;
    return fib(n-1) + fib(n-2);          // O(2^n) — always memoize in practice
}

// Tail recursion (compiler MAY optimize, but C++ doesn't guarantee TCO)
int sumTail(int n, int acc = 0) {
    if (n == 0) return acc;
    return sumTail(n-1, acc + n);
}
```

**Recursion Tree Visualization (fib(4)):**
```
                fib(4)
              /        \
          fib(3)        fib(2)
         /     \        /    \
     fib(2)  fib(1)  fib(1) fib(0)
     /    \
  fib(1) fib(0)

Total calls: exponential — fib(3) and fib(2) subtrees are recomputed repeatedly.
This redundancy is exactly what memoization (Section 33 - DP) eliminates.
```

**Common Mistakes:**
- Missing or wrong base case → infinite recursion → stack overflow.
- Assuming C++ does tail-call optimization — it does **not guarantee** this (unlike some functional languages); deep tail recursion can still overflow the stack.
- Recomputing overlapping subproblems (like naive `fib`) without memoization → exponential blowup for `n` as small as ~40.
- Recursion depth limit: default stack is typically ~1MB-8MB; a recursive DFS on a skewed tree/graph with `10^5`+ nodes can crash — convert to iterative with explicit stack when depth could be large.

**Interview Tip:** Always state the **recurrence relation** and **base case** out loud before coding — interviewers grade the thought process, not just working code.

---

## 23. Backtracking

**Concept:** Recursion + explicit "undo" of a choice — explore, recurse, then revert state to try the next option. Used for permutations, combinations, subsets, and constraint-satisfaction (N-Queens, Sudoku).

### 23.1 Subsets (Power Set)

```cpp
void backtrackSubsets(vector<int>& nums, int idx, vector<int>& cur, vector<vector<int>>& result) {
    result.push_back(cur);                 // every partial state IS a valid subset
    for (int i = idx; i < nums.size(); i++) {
        cur.push_back(nums[i]);             // choose
        backtrackSubsets(nums, i+1, cur, result);  // explore
        cur.pop_back();                      // un-choose (backtrack)
    }
}
```

### 23.2 Permutations

```cpp
void backtrackPermute(vector<int>& nums, vector<bool>& used, vector<int>& cur, vector<vector<int>>& result) {
    if (cur.size() == nums.size()) { result.push_back(cur); return; }
    for (int i = 0; i < nums.size(); i++) {
        if (used[i]) continue;
        used[i] = true;
        cur.push_back(nums[i]);
        backtrackPermute(nums, used, cur, result);
        cur.pop_back();
        used[i] = false;   // backtrack
    }
}
```

### 23.3 N-Queens (constraint satisfaction template)

```cpp
bool isSafe(vector<int>& cols, int row, int col) {
    for (int r = 0; r < row; r++) {
        int c = cols[r];
        if (c == col || abs(c-col) == abs(r-row)) return false;  // same col or same diagonal
    }
    return true;
}

void solveNQueens(int row, int n, vector<int>& cols, int& count) {
    if (row == n) { count++; return; }
    for (int col = 0; col < n; col++) {
        if (isSafe(cols, row, col)) {
            cols[row] = col;                       // place queen
            solveNQueens(row+1, n, cols, count);    // recurse
            // no explicit "unplace" needed — cols[row] gets overwritten next iteration
        }
    }
}
```

**Dry Run — Subsets of [1,2]:**
```
backtrack(idx=0, cur=[])
  push cur=[] to result           result = [[]]
  i=0: cur=[1]
    backtrack(idx=1, cur=[1])
      push cur=[1]                 result = [[], [1]]
      i=1: cur=[1,2]
        backtrack(idx=2, cur=[1,2])
          push cur=[1,2]           result = [[], [1], [1,2]]
      pop -> cur=[1]
  pop -> cur=[]
  i=1: cur=[2]
    backtrack(idx=2, cur=[2])
      push cur=[2]                 result = [[], [1], [1,2], [2]]
  pop -> cur=[]
Final: [[], [1], [1,2], [2]]
```

**Common Mistakes:**
- Forgetting to **undo** the choice (`pop_back()`, `used[i] = false`) after recursing → state leaks into sibling branches, silently wrong results.
- Pushing a **reference** to `cur` into `result` instead of a **copy** — since `cur` is mutated afterward, all stored "copies" end up reflecting the final state. Always `result.push_back(cur)` (which copies by value) not a pointer/reference.
- Not pruning early (checking constraints before recursing rather than after building a full invalid state) → massive unnecessary branching, especially in N-Queens/Sudoku.
- Off-by-one in `idx` vs `idx+1` when deciding whether elements can be reused (subsets/combinations don't reuse index, but "combination sum with repetition" does — know which variant you need).

**Interview Tip:** Backtracking time complexity is almost always exponential (`O(2^n)` for subsets, `O(n!)` for permutations) — always state this upfront; interviewers want to hear you acknowledge the exponential nature and discuss pruning strategies.

---

## 24. Greedy

**Concept:** Make the locally optimal choice at each step, hoping it leads to a global optimum. Works only when the problem has the **greedy-choice property** + **optimal substructure** — always verify (or prove via exchange argument) before trusting a greedy solution.

### 24.1 Activity Selection / Interval Scheduling

```cpp
// Maximum number of non-overlapping intervals
int maxNonOverlapping(vector<pair<int,int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto&a, auto&b){
        return a.second < b.second;   // sort by END time — the key greedy insight
    });
    int count = 0, lastEnd = INT_MIN;
    for (auto& [start, end] : intervals) {
        if (start >= lastEnd) { count++; lastEnd = end; }
    }
    return count;
}
```

### 24.2 Fractional Knapsack

```cpp
double fractionalKnapsack(vector<pair<int,int>>& items, int capacity) { // {value, weight}
    sort(items.begin(), items.end(), [](auto&a, auto&b){
        return (double)a.first/a.second > (double)b.first/b.second; // sort by value/weight desc
    });
    double totalValue = 0;
    for (auto& [value, weight] : items) {
        if (capacity >= weight) { totalValue += value; capacity -= weight; }
        else { totalValue += value * ((double)capacity/weight); break; }
    }
    return totalValue;
}
```

### 24.3 Huffman Encoding Style / Merge Cost Problems

```cpp
// Minimum cost to merge n ropes/files into one (classic min-heap greedy)
long long minMergeCost(vector<int>& lengths) {
    priority_queue<int, vector<int>, greater<int>> pq(lengths.begin(), lengths.end());
    long long totalCost = 0;
    while (pq.size() > 1) {
        int a = pq.top(); pq.pop();
        int b = pq.top(); pq.pop();
        totalCost += a + b;
        pq.push(a+b);
    }
    return totalCost;
}
```

**Common Mistakes:**
- Applying greedy without proving correctness — greedy "feels right" often but fails silently on edge cases (e.g., naive coin change greedy fails for non-canonical coin systems like {1,3,4} for amount=6).
- Sorting by the wrong key: interval scheduling MUST sort by end time, not start time or duration, to guarantee optimality.
- Forgetting fractional knapsack ≠ 0/1 knapsack — greedy works for fractional but 0/1 knapsack requires DP (Section 33), a classic interview trap.

**Interview Tip:** When proposing a greedy solution, briefly justify it (exchange argument or matroid intuition) — interviewers often push back with "what if..." counterexamples if you can't defend the greedy choice.

---

## 25. Trees

**Concept:** Hierarchical node structure — one root, each node has children. Binary trees (≤2 children) are the interview staple.

### 25.1 Node Definition & Traversals

```cpp
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// DFS Traversals — O(n) each
void preorder(TreeNode* root, vector<int>& out) {   // Root -> Left -> Right
    if (!root) return;
    out.push_back(root->val);
    preorder(root->left, out);
    preorder(root->right, out);
}
void inorder(TreeNode* root, vector<int>& out) {    // Left -> Root -> Right (sorted for BST!)
    if (!root) return;
    inorder(root->left, out);
    out.push_back(root->val);
    inorder(root->right, out);
}
void postorder(TreeNode* root, vector<int>& out) {  // Left -> Right -> Root
    if (!root) return;
    postorder(root->left, out);
    postorder(root->right, out);
    out.push_back(root->val);
}

// BFS Traversal (Level Order)
vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int sz = q.size();
        vector<int> level;
        for (int i = 0; i < sz; i++) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
        result.push_back(level);
    }
    return result;
}
```

### 25.2 Height, Diameter, LCA

```cpp
int height(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Diameter — longest path between any two nodes (may not pass through root)
int diameter(TreeNode* root, int& best) {
    if (!root) return 0;
    int lh = diameter(root->left, best);
    int rh = diameter(root->right, best);
    best = max(best, lh + rh);              // path through this node
    return 1 + max(lh, rh);
}

// Lowest Common Ancestor (binary tree, not necessarily BST)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (!root || root == p || root == q) return root;
    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);
    if (left && right) return root;          // p and q found in different subtrees
    return left ? left : right;
}
```

**Dry Run — Diameter of tree `1 -> (2 -> (4, 5), 3)`:**
```
diameter(4): leaf, lh=0,rh=0, best=max(best,0)=0, return 1
diameter(5): leaf, lh=0,rh=0, best=max(best,0)=0, return 1
diameter(2): lh=height(4)=1, rh=height(5)=1, best=max(0,1+1)=2, return 1+max(1,1)=2
diameter(3): leaf, lh=0,rh=0, best stays 2, return 1
diameter(1): lh=diameter(2)=2, rh=diameter(3)=1, best=max(2, 2+1)=3, return 1+max(2,1)=3
Final diameter (edges) = 3
```

**Common Mistakes:**
- Confusing "diameter as number of nodes" vs "diameter as number of edges" — clarify with interviewer; the formula differs by exactly 1.
- LCA: assuming a plain binary tree is a BST and using value comparisons — only valid if explicitly a BST (see Section 26 for the O(h) BST-specific LCA).
- Forgetting the null check `if (!root) return ...;` at the top of every recursive tree function — the #1 source of segfaults in tree problems.
- BFS level order: forgetting to snapshot `sz = q.size()` **before** the inner loop — since the queue size changes as children are pushed, this causes the level boundaries to be wrong.

**Interview Tip:** "Diameter of binary tree" and "Lowest Common Ancestor" are top-5 most-asked tree interview questions — both use the same core pattern: compute a value bottom-up while updating a global/reference "best" answer along the way.

---

## 26. BST (Binary Search Tree)

**Concept:** Binary tree with the invariant: left subtree < node < right subtree. Enables O(h) (O(log n) if balanced) search/insert/delete.

```cpp
// Search — O(h)
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    return val < root->val ? searchBST(root->left, val) : searchBST(root->right, val);
}

// Insert — O(h)
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Delete — O(h), the trickiest of the three (3 cases)
TreeNode* deleteBST(TreeNode* root, int key) {
    if (!root) return nullptr;
    if (key < root->val) root->left = deleteBST(root->left, key);
    else if (key > root->val) root->right = deleteBST(root->right, key);
    else {
        // Case 1: no children, Case 2: one child
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        // Case 3: two children — replace with inorder successor (min of right subtree)
        TreeNode* successor = root->right;
        while (successor->left) successor = successor->left;
        root->val = successor->val;
        root->right = deleteBST(root->right, successor->val);
    }
    return root;
}

// Validate BST — O(n), classic interview trap
bool isValidBST(TreeNode* root, long long lo = LLONG_MIN, long long hi = LLONG_MAX) {
    if (!root) return true;
    if (root->val <= lo || root->val >= hi) return false;
    return isValidBST(root->left, lo, root->val) && isValidBST(root->right, root->val, hi);
}

// LCA in a BST — O(h), much simpler than general binary tree LCA
TreeNode* lcaBST(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root) {
        if (p->val < root->val && q->val < root->val) root = root->left;
        else if (p->val > root->val && q->val > root->val) root = root->right;
        else return root;
    }
    return nullptr;
}
```

**Common Mistakes:**
- `isValidBST`: checking only immediate children (`root->left->val < root->val < root->right->val`) instead of the **full range** constraint — fails for cases where a deep left-subtree node violates the ancestor's constraint even though it satisfies its immediate parent.
- Delete case 3: after copying the successor's value, forgetting to actually delete the successor node from the right subtree → duplicate values.
- BST operations degrade to O(n) on an unbalanced/skewed tree (e.g., inserting sorted data creates a linked-list-shaped tree) — for guaranteed O(log n), a self-balancing tree (AVL/Red-Black) or `std::set`/`map` (already balanced) is needed.
- Inorder traversal of a valid BST gives a **sorted sequence** — a fast, simple way to validate a BST if you don't want the range-based recursive approach.

**Interview Tip:** "Validate BST" trips up most candidates who only check the immediate parent-child relationship — always mention you're tracking a valid `(lo, hi)` range through recursion.

---

## 27. Binary Lifting

**Concept:** Precompute `2^k`-th ancestors for every node in O(n log n), enabling O(log n) LCA queries and "k-th ancestor" queries — much faster than O(n) naive climbing, critical for large trees with many queries.

```cpp
const int LOG = 20; // enough for n up to ~10^6 (2^20 > 10^6)
vector<vector<int>> up;   // up[node][k] = 2^k-th ancestor of node
vector<int> depth;

void dfs(int u, int parent, vector<vector<int>>& adj) {
    up[u][0] = parent;
    for (int k = 1; k < LOG; k++)
        up[u][k] = (up[u][k-1] == -1) ? -1 : up[up[u][k-1]][k-1];
    for (int v : adj[u]) {
        if (v != parent) { depth[v] = depth[u] + 1; dfs(v, u, adj); }
    }
}

int kthAncestor(int node, int k) {
    for (int i = 0; i < LOG && node != -1; i++)
        if (k & (1 << i)) node = up[node][i];
    return node;
}

int lca(int u, int v) {
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];
    u = kthAncestor(u, diff);          // bring both to the same depth
    if (u == v) return u;
    for (int k = LOG-1; k >= 0; k--) {
        if (up[u][k] != up[v][k]) { u = up[u][k]; v = up[v][k]; }
    }
    return up[u][0];                    // one final step to the common ancestor
}
```

**Dry Run — kthAncestor climbing 5 levels (binary of 5 = 101):**
```
k=5 = binary 101
bit 0 (value 1) set: node = up[node][0]  (jump 1)
bit 1 (value 2) not set: skip
bit 2 (value 4) set: node = up[node][2]  (jump 4)
Total jumped: 1 + 4 = 5 levels ✓ in O(log k) jumps instead of O(k) steps
```

**Common Mistakes:**
- `LOG` too small for `n` — must satisfy `2^LOG > n`; using `LOG=20` for `n=10^7` is insufficient (need `LOG=24`).
- Forgetting to bring both nodes to the same depth **before** the binary-lifting-up LCA loop — the core algorithm assumes equal depth as a precondition.
- Off-by-one: the final `return up[u][0]` step after the loop is easy to forget (the loop stops one level above the actual LCA by design, to avoid overshooting past it).
- Not handling `up[node][k] == -1` (out-of-tree) sentinel correctly — always guard `if (up[u][k-1] == -1) up[u][k] = -1;` else infinite/garbage indexing.

**CP Trick:** Binary lifting isn't just for LCA — it generalizes to any "apply a function `f` (like 'next node in permutation') `k` times fast" problem, e.g., functional graph cycle-jump queries.

---

*End of Part 4.*

---

## 28. Graph

**Concept:** Nodes (vertices) connected by edges — directed/undirected, weighted/unweighted. Represented via adjacency list (sparse, most common) or adjacency matrix (dense, O(V²) space).

### 28.1 Representation

```cpp
int n, m; // n = nodes, m = edges
vector<vector<int>> adj(n+1);              // unweighted adjacency list
vector<vector<pair<int,int>>> adjW(n+1);   // weighted: {neighbor, weight}

// Add edge
adj[u].push_back(v);
adj[v].push_back(u);                        // omit this line for DIRECTED graphs

adjW[u].push_back({v, weight});
adjW[v].push_back({u, weight});              // omit for directed

// Adjacency matrix — O(V^2) space, O(1) edge lookup, good for dense graphs
vector<vector<int>> matrix(n+1, vector<int>(n+1, 0));
matrix[u][v] = 1; matrix[v][u] = 1;
```

### 28.2 DFS & BFS

```cpp
void dfs(int u, vector<vector<int>>& adj, vector<bool>& visited) {
    visited[u] = true;
    for (int v : adj[u]) if (!visited[v]) dfs(v, adj, visited);
}

vector<int> bfs(int src, vector<vector<int>>& adj, int n) {
    vector<int> dist(n+1, -1);
    queue<int> q;
    dist[src] = 0; q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u])
            if (dist[v] == -1) { dist[v] = dist[u]+1; q.push(v); }
    }
    return dist;
}

// Iterative DFS (avoids stack overflow on large/skewed graphs)
void dfsIterative(int src, vector<vector<int>>& adj, vector<bool>& visited) {
    stack<int> st;
    st.push(src);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (int v : adj[u]) if (!visited[v]) st.push(v);
    }
}
```

**Common Mistakes:**
- Forgetting `adj[v].push_back(u)` for undirected graphs → treats it as directed, breaks connectivity logic.
- Recursive DFS on graphs with `10^5`+ nodes in a skewed/path-like shape → stack overflow; use iterative DFS.
- Not marking a node visited **before** fully processing it in BFS (marking too late) → the same node gets pushed to the queue multiple times, causing TLE on dense graphs.
- 1-indexed vs 0-indexed node numbering mismatches between input parsing and adjacency list sizing.

**Interview Tip:** Always clarify directed vs undirected and weighted vs unweighted before coding — the adjacency list construction (and subsequent algorithm choice) depends entirely on this.

---

## 29. Union Find (Disjoint Set Union / DSU)

**Concept:** Maintains a partition of elements into disjoint sets with near-O(1) `find` and `union` operations via path compression + union by rank/size. Essential for Kruskal's MST, connectivity queries, and cycle detection in undirected graphs.

```cpp
class DSU {
    vector<int> parent, rank_;
public:
    DSU(int n) : parent(n), rank_(n, 0) {
        iota(parent.begin(), parent.end(), 0);   // each node is its own parent initially
    }
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);  // path compression
        return parent[x];
    }
    bool unite(int x, int y) {
        int rx = find(x), ry = find(y);
        if (rx == ry) return false;               // already in same set — would form a cycle
        if (rank_[rx] < rank_[ry]) swap(rx, ry);
        parent[ry] = rx;                            // union by rank
        if (rank_[rx] == rank_[ry]) rank_[rx]++;
        return true;
    }
    bool connected(int x, int y) { return find(x) == find(y); }
};
```

**Dry Run — unite(0,1), unite(2,3), unite(1,2):**
```
Initial: parent = [0,1,2,3], rank = [0,0,0,0]
unite(0,1): find(0)=0, find(1)=1, ranks equal(0,0), parent[1]=0, rank[0]=1
   parent = [0,0,2,3]
unite(2,3): find(2)=2, find(3)=3, ranks equal, parent[3]=2, rank[2]=1
   parent = [0,0,2,2]
unite(1,2): find(1)-> parent[1]=0, so find(1)=0. find(2)=2.
   rank[0]=1, rank[2]=1, equal -> parent[2]=0, rank[0]=2
   parent = [0,0,0,2]  (find(2) still resolves to 0 via path compression next call)
Final: all 4 nodes connected under root 0
```

**Common Mistakes:**
- Forgetting **path compression** (`parent[x] = find(parent[x])`) → `find` degrades to O(n) on a chain, defeating the whole purpose of DSU.
- Forgetting **union by rank/size** → same degradation risk on adversarial unite order.
- Using `unite` return value incorrectly — `unite` returning `false` means a cycle would form (critical for Kruskal's MST edge-skipping logic and cycle detection).
- Off-by-one: DSU sized for `n` elements but graph is 1-indexed → index out of bounds; size DSU as `n+1` for 1-indexed problems.

**Interview Tip:** "Number of Provinces/Connected Components", "Redundant Connection" (cycle detection), and "Accounts Merge" are classic DSU interview questions — the `unite` returning `false` on a cycle is often the entire solution.

---

## 30. Topological Sort

**Concept:** Linear ordering of nodes in a **Directed Acyclic Graph (DAG)** such that for every edge `u->v`, `u` comes before `v`. Undefined for graphs with cycles.

### 30.1 Kahn's Algorithm (BFS-based, also detects cycles)

```cpp
vector<int> topoSortKahn(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; u++)
        for (int v : adj[u]) indegree[v]++;

    queue<int> q;
    for (int i = 0; i < n; i++) if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u]) if (--indegree[v] == 0) q.push(v);
    }

    if (order.size() != n) return {};  // CYCLE detected — no valid topo order exists
    return order;
}
```

### 30.2 DFS-based Topological Sort

```cpp
void dfsTopo(int u, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& st) {
    visited[u] = true;
    for (int v : adj[u]) if (!visited[v]) dfsTopo(v, adj, visited, st);
    st.push(u);    // push AFTER visiting all descendants — key insight
}

vector<int> topoSortDFS(int n, vector<vector<int>>& adj) {
    vector<bool> visited(n, false);
    stack<int> st;
    for (int i = 0; i < n; i++) if (!visited[i]) dfsTopo(i, adj, visited, st);
    vector<int> order;
    while (!st.empty()) { order.push_back(st.top()); st.pop(); }
    return order;
}
```

**Dry Run — Kahn's on edges 0->1, 0->2, 1->3, 2->3:**
```
indegree = [0, 1, 1, 2]
q initially: [0] (only node 0 has indegree 0)
pop 0, order=[0]. decrement 1->0, 2->0. push both: q=[1,2]
pop 1, order=[0,1]. decrement 3: indegree[3]=1 (not 0 yet)
pop 2, order=[0,1,2]. decrement 3: indegree[3]=0, push 3. q=[3]
pop 3, order=[0,1,2,3]
Final topo order: [0,1,2,3]
```

**Common Mistakes:**
- Using topological sort on a graph with a cycle → Kahn's `order.size() != n` check is mandatory to detect this; DFS-based version needs a separate visited-state (white/gray/black) cycle check if cycle detection is also required.
- Confusing DFS-based topo sort push order — must push to the stack **after** recursing into all neighbors (post-order), then reverse (or read the stack top-to-bottom).
- Multiple valid topological orders can exist for the same DAG — don't assume uniqueness; if the problem needs a *specific* one (e.g., lexicographically smallest), use a priority_queue instead of a plain queue in Kahn's.

**Interview Tip:** "Course Schedule" (I & II) is the canonical topological sort interview question — I asks "is it possible" (cycle detection), II asks for the actual order.

---

## 31. Shortest Path

**Concept:** Find minimum-cost path(s) from source to target(s). Algorithm choice depends on edge weights (unweighted/positive/negative) and whether you need single-source or all-pairs.

| Algorithm | Handles Negative Weights? | Time Complexity | Use Case |
|---|---|---|---|
| BFS | N/A (unweighted only) | O(V+E) | unweighted shortest path |
| Dijkstra | No | O((V+E) log V) | single-source, non-negative weights |
| Bellman-Ford | Yes (detects negative cycles) | O(V·E) | single-source, negative weights allowed |
| Floyd-Warshall | Yes (detects negative cycles) | O(V³) | all-pairs shortest path |

### 31.1 Dijkstra's Algorithm

```cpp
vector<long long> dijkstra(int src, int n, vector<vector<pair<int,int>>>& adj) {
    vector<long long> dist(n, LLONG_MAX);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;              // stale entry, skip — CRITICAL optimization
        for (auto& [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
```

### 31.2 Bellman-Ford (handles negative weights, detects negative cycles)

```cpp
vector<long long> bellmanFord(int src, int n, vector<tuple<int,int,int>>& edges, bool& hasNegCycle) {
    vector<long long> dist(n, LLONG_MAX);
    dist[src] = 0;
    for (int i = 0; i < n-1; i++)                          // relax all edges n-1 times
        for (auto& [u, v, w] : edges)
            if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;

    hasNegCycle = false;
    for (auto& [u, v, w] : edges)                            // one more pass to detect negative cycle
        if (dist[u] != LLONG_MAX && dist[u] + w < dist[v])
            hasNegCycle = true;

    return dist;
}
```

### 31.3 Floyd-Warshall (all-pairs)

```cpp
void floydWarshall(vector<vector<long long>>& dist, int n) {
    // dist[i][j] pre-initialized: 0 if i==j, edge weight if direct edge, INF otherwise
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] < LLONG_MAX && dist[k][j] < LLONG_MAX)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}
```

**Common Mistakes:**
- Using Dijkstra on a graph with **negative weights** → silently wrong answers (Dijkstra's greedy assumption breaks). Must use Bellman-Ford instead.
- Forgetting the `if (d > dist[u]) continue;` stale-check in Dijkstra with a priority_queue → still correct, but performance degrades since outdated entries aren't skipped (can matter for TLE on dense graphs with many `pq.push` calls).
- Floyd-Warshall loop order matters: `k` (intermediate node) **must** be the outermost loop — swapping `k` with `i`/`j` breaks correctness.
- Integer overflow: `dist[i][k] + dist[k][j]` when both are already "INF" sentinels → must guard against adding two INF values (overflows past `LLONG_MAX`), hence the explicit `if` guard.
- Bellman-Ford: exactly `n-1` relaxation passes are needed (not `n`, not fewer) — the negative cycle check requires one additional pass beyond that.

**Interview Tip:** "Network Delay Time" (Dijkstra), "Cheapest Flights Within K Stops" (Bellman-Ford-style with a k-step limit) are common shortest-path interview questions — always ask about edge weight constraints (can they be negative?) before picking an algorithm.

---

## 32. MST (Minimum Spanning Tree)

**Concept:** A subset of edges connecting all vertices with minimum total edge weight, no cycles. Two classic greedy algorithms, both provably optimal.

### 32.1 Kruskal's Algorithm (edge-based, uses DSU)

```cpp
long long kruskalMST(int n, vector<tuple<int,int,int>>& edges) { // (weight, u, v)
    sort(edges.begin(), edges.end());               // sort by weight ascending
    DSU dsu(n);
    long long totalWeight = 0;
    int edgesUsed = 0;
    for (auto& [w, u, v] : edges) {
        if (dsu.unite(u, v)) {                        // returns false if would form a cycle
            totalWeight += w;
            edgesUsed++;
            if (edgesUsed == n-1) break;                // MST complete
        }
    }
    return totalWeight;  // if edgesUsed < n-1, graph was disconnected — no valid MST
}
```

### 32.2 Prim's Algorithm (node-based, uses priority_queue)

```cpp
long long primMST(int src, int n, vector<vector<pair<int,int>>>& adj) {
    vector<bool> inMST(n, false);
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; // {weight, node}
    pq.push({0, src});
    long long totalWeight = 0;
    int nodesUsed = 0;
    while (!pq.empty() && nodesUsed < n) {
        auto [w, u] = pq.top(); pq.pop();
        if (inMST[u]) continue;
        inMST[u] = true;
        totalWeight += w;
        nodesUsed++;
        for (auto& [v, wt] : adj[u])
            if (!inMST[v]) pq.push({wt, v});
    }
    return totalWeight;
}
```

**Common Mistakes:**
- Kruskal's: forgetting to sort edges by weight first → produces a wrong (non-minimum) spanning tree.
- Kruskal's: not checking `edgesUsed == n-1` at the end → if the graph is disconnected, the algorithm silently returns a "forest" total instead of correctly reporting "no MST exists."
- Prim's: forgetting the `if (inMST[u]) continue;` stale-check → processes the same node multiple times, inflating `totalWeight` incorrectly.
- Choosing Kruskal's for a dense graph (E close to V²) — Prim's with a priority_queue (O(E log V)) or Prim's with adjacency matrix (O(V²)) can be more efficient depending on density; Kruskal's O(E log E) sorting cost dominates on dense graphs.

**Interview Tip:** Kruskal's is usually easier to reason about and implement from scratch in an interview (leverages DSU, which you may have already written); Prim's is preferred when the graph is given as an adjacency list and you want to avoid an explicit edge list + sort.

---

*End of Part 5. Next (Part 6): Dynamic Programming (the biggest section — 1D/2D DP, knapsack family, LCS/LIS, DP on trees/bitmask), Segment Tree, Fenwick Tree, Sparse Table. Say "continue" to keep going.*
