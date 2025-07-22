
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


Sliding Window is a powerful technique to solve subarray/substring problems efficiently.  
There are **two types** of sliding window approaches:
1. **Fixed (Static) Size Sliding Window**  
2. **Variable Size Sliding Window**

---

## **1. Fixed (Static) Size Sliding Window**

### **Concept**
- The window size is **constant (k)**.
- Used for problems like:
  - Maximum/Minimum sum of a subarray of size `k`.
  - Maximum/Minimum average of `k` elements.
  - First negative number in every `k` size window.

---

### **General Steps**
1. Start with two pointers `left` and `right`.
2. Expand the `right` pointer until the window reaches size `k`.
3. Process the current window (e.g., update the answer).
4. Slide the window by incrementing `left` (removing the effect of the leftmost element).

<img width="943" height="786" alt="Screenshot 2025-07-20 222235" src="https://github.com/user-attachments/assets/b878e2e7-3a87-4854-b362-f65b03491e79" />


---




# Variable Size Sliding Window Template

## **Concept**
The **variable size sliding window** technique is used when:
- We need to find the **longest/shortest subarray/substring** with certain properties.
- The window expands and contracts dynamically based on conditions.

---

## **General Steps**
1. Initialize two pointers `left` and `right` to represent the current window.
2. Use a data structure (like `map`, `set`, `vector`, or just a sum counter) to store the window state.
3. Expand the `right` pointer step by step.
4. If the current window violates a condition, **shrink** it by moving the `left` pointer until it satisfies the condition.
5. Update the **answer** (e.g., max/min length, sum) whenever the condition is satisfied.

<img width="966" height="766" alt="Screenshot 2025-07-20 221951" src="https://github.com/user-attachments/assets/b2484b83-70ea-45e5-b315-b17cb5a2b76f" />

---
# Problems

# Static Window Size

- [Max Sum Subarray of size K](https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1)
- [First negative in every window of size k](https://www.geeksforgeeks.org/problems/first-negative-integer-in-every-window-of-size-k3345/1)
- [Count Occurences of Anagrams](https://www.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/1)
- [ Sliding Window Maximum](https://leetcode.com/problems/sliding-window-maximum/description/)
- [ Binary Subarrays With Sum](https://leetcode.com/problems/binary-subarrays-with-sum/description/)


# Variable Window Size
- [ Longest Substring Without Repeating Characters](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)
- [Max Consecutive Ones III](https://leetcode.com/problems/max-consecutive-ones-iii/description/)
- [904. Fruit Into Baskets](https://leetcode.com/problems/fruit-into-baskets/description/)
- [424. Longest Repeating Character Replacement](https://leetcode.com/problems/longest-repeating-character-replacement/description/)
- [992. Subarrays with K Different Integers](https://leetcode.com/problems/subarrays-with-k-different-integers/) 🔴 ⭐
- [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/)  🔴 ⭐



