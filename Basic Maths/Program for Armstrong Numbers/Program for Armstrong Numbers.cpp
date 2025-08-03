// User function Template for C++
class Solution {
  public:
    bool armstrongNumber(int n) {
        // code here
        int number =n;
        vector<int>rem;
        int ans =0;
       
       while(n!=0) 
       {
           
        int fact = n%10;
        rem.push_back(fact);
        n=n/10;
       }
       for(int i=0;i<rem.size();i++)
       {
           ans+=rem[i]*rem[i]*rem[i];
       }
       
       if(ans==number)
       {
           return true;
       }
       else{
           return false;
       }
        
        
    }
};
