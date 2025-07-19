
# Sliding Window Technique

## Overview
The **sliding window technique** is a powerful approach for solving problems involving **subarrays or substrings** of contiguous elements. Instead of recalculating results for every possible subarray, we maintain a **window (range of indices)** that moves (slides) across the array or string while updating results efficiently.

---

## When to Use Sliding Window?
- When the problem involves **subarrays/substrings** (contiguous elements).
- When you need to find:
  - Maximum or minimum sum of `k` consecutive elements.
  - Longest/shortest substring with certain conditions.
  - Number of substrings/subarrays that meet a specific criterion.
  
---

## Types of Sliding Window
### 1. **Fixed-Size Window**
- The window size `k` is known.
- Move the window forward by adding the next element and removing the first element.
- **Example:** Maximum sum subarray of size `k`.

### 2. **Variable-Size Window**
- The window size changes dynamically based on a condition.
- Expand the window (right pointer) and shrink it (left pointer) when necessary.
- **Example:** Longest substring without repeating characters.

---
# Problems

- [Max Sum Subarray of size K](https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1)

## General Approach

### **Fixed-Size Window Template**
```cpp

int i = 0, j = 0;
while (j < n) {
    // Add element to window

    while (condition_not_satisfied) {
        // Shrink window
        i++;
    }

    // Update result
    j++;
}

---


