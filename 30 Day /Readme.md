# 🚀 30 Day Full DSA Challenge

Track your progress day-wise with problem links, video explanations, and structured approaches.

---

## 📅 Day 1

| Problem | YouTube Video | Approach |
|--------|----------------|----------|
| **Set Matrix Zeroes** | [▶️ Watch](https://www.youtube.com/watch?v=A0_hEzQFP9U) | <details><summary>🔍 Click to Expand</summary>

**Problem Statement:**  
Given an `m x n` matrix, if an element is 0, set its entire row and column to 0. Do it in-place if possible.

**Brute Force:**  
- Use a copy of the matrix.
- For each 0, set corresponding row & column to 0.

**Better Approach:**  
- Use `row[]` and `col[]` arrays to mark 0s.
- Time: O(n*m), Space: O(n + m)

**Optimal (In-place):**  
- Use 1st row/col as markers.
- Handle row0 and col0 separately.
- Time: O(n*m), Space: O(1)

</details> |
