class Solution {
public:
    bool isPalindromeUtil(string &s, int start, int end) {
        if (start >= end) return true;  // base case: all chars matched

        if (s[start] != s[end]) return false;  // mismatch

        return isPalindromeUtil(s, start + 1, end - 1);  // recurse
    }

    bool isPalindrome(string s) {
        return isPalindromeUtil(s, 0, s.size() - 1);
    }
};

