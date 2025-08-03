class Solution {
  public:
    void print_divisors(int n) {
        // // Code here.
      // brute approch
        // vector<int>ans;
        
        // for(int i=1;i<=n;i++)
        // {
        //     if(n%i==0)
        //     {
        //      ans.push_back(i);
        //     }
        // }
        // // return ans;
        // for(int it:ans){
        //     cout<<it<<" ";
        // }

      class Solution {
  public:
    void print_divisors(int n) {
        vector<int> small, large;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                small.push_back(i);
                if (i != n / i) {
                    large.push_back(n / i);
                }
            }
        }

        // Print all: small divisors + reversed large divisors
        for (int x : small) cout << x << " ";
        for (int i = large.size() - 1; i >= 0; i--) cout << large[i] << " ";
    }
};

    }
};
