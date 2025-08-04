class Solution {
  public:
    int result=1;
   
    void factorial(int n) {
        // code here
        
        if (n == 0) {
            cout << result << endl;  
            return;
        }

        result *= n;                
        factorial(n - 1);    
    }
};
