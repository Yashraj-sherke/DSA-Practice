class Solution {
  public:
    bool isPalindrome(int n) {
        int original = n;          // Store the original number
        int reversed = 0;
        
        while(n > 0) {
            int lastDigit = n % 10;
            reversed = reversed * 10 + lastDigit;
            n = n / 10;
        }
        
        return (original == reversed);
    }
};
