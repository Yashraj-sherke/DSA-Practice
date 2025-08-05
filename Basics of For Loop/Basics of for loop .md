🧠 🔁 🔥 Master List: 40 For Loop Variations for DSA
# 📦 [A] Standard Traversal Loops
for (int i = 0; i < n; i++)

for (int i = n-1; i >= 0; i--)

for (int i = 0; i < n; i += 2)

for (int i = 1; i < n; i *= 2)

for (int i = n; i > 0; i /= 2)

for (int i = 0; i <= n; i++)

for (int i = n-1; i > 0; i--)

for (int i = 0; i < arr.size(); i++)

for (auto it : arr) (range-based for)

for (auto &it : arr) (reference — update allowed)

# 🧮 [B] Nested Loops (For Pairs, Grids, Subarrays)
for (int i = 0; i < n; i++) for (int j = 0; j < n; j++)

for (int i = 0; i < n; i++) for (int j = i + 1; j < n; j++)

for (int i = 0; i < n; i++) for (int j = i; j < n; j++)

for (int row = 0; row < r; row++) for (int col = 0; col < c; col++)

for (int i = 0; i < n; i++) for (int j = n-1; j > i; j--)

# 🪟 [C] Sliding Window / Fixed Window
for (int i = 0; i + k <= n; i++) (window of size k)

for (int i = 0, j = 0; j < n; j++) (shrinking window with two pointers)

for (int i = 0; i < n; i++) while (window condition) i++

for (int i = 0; i < s.length(); i++) (substring or char window)

for (int i = 0; i <= n-k; i++) (strictly k-sized window)

# 🏃‍♂️ [D] Two Pointer / Dual Loop Patterns
for (int i = 0, j = n - 1; i < j;) (two ends inward)

for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++)

for (int i = 0, j = 0; i < n && j < n;) (two pointers together)

for (int i = 0; i < n; i++) while(j < n && condition)

for (int i = 0; i < s.size(); i++) for (int len = 1; i+len <= s.size(); len++) (for substrings)

# 🎯 [E] Condition-Driven Loops
for (int i = 0; i < n && found == false; i++)

for (int i = 0; i < n; i++) if (arr[i] == target) break;

for (int i = 0; i < n; i++) if (arr[i] % 2 == 0) continue;

for (int i = 0; i < n && isValid(i); i++)

for (int i = 0; i < min(n, 100); i++) (limited check)

# 🧵 [F] Special Step / Jump Patterns
for (int i = 0; i < n; i += k) (jump in steps)

for (int i = 1; i <= n; i *= 2) (logarithmic loop)

for (int i = n; i > 0; i /= 2) (reverse log)

for (int i = 0; i*i <= n; i++) (square root based)

for (int i = n; i > 0; i -= k) (reverse jump)

# 📚 [G] STL/Map/Set Iteration Loops
for (auto it = mp.begin(); it != mp.end(); it++)

for (auto &[key, val] : mp) (structured binding)

for (auto it = st.begin(); it != st.end(); it++)

for (auto x : unordered_set)

for (auto x : vector<vector<int>>) (2D vector)

# 🧠 [H] Advanced Control
for (int i = 0;; i++) (infinite until break)

for (;;) (infinite loop)

for (int i = 0; i < arr.size(); i++) while (someStackCondition)

for (int bit = 0; bit < 32; bit++) (bitwise logic)

for (int mask = 0; mask < (1 << n); mask++) (subsets using bitmasking)
