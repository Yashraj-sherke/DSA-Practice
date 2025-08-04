class Solution {
  public:
    void printNos(int n) {
        // Code here
        // base case
        
        if(n==0) return;
        
        // recursive
        
         printNos(n-1);
         
         cout<<n<<" ";
    }
};
