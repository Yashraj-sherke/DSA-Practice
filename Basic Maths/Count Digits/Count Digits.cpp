class Solution {
  public:
    int countDigits(int n) {
        // code here
        // firstly convert the number to string
        
    //   string s  = to_string(n);
    //   return s.length();
        
        
        int count = 0;
        
        while(n>0)
        {
         n = n/10;
            count++;
        }
        
        return count;
    }
};
