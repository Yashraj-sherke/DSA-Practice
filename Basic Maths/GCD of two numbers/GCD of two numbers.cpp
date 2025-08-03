class Solution {
  public:
    int gcd(int a, int b) {
        // if (b == 0)
        //     return a;
        // return gcd(b, a % b);
        
        // brute approch
        
        int  ans = INT_MIN;
        
        
        for(int i=1;i<=min(a,b);i++)
        {
            if(a%i==0 && b%i==0)
            {
                ans =i;
            }
        }
        return ans;
    }
};
