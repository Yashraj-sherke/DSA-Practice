class Solution {
public:
    int n ;
    int dp[1001][1001];
     int solve(vector<vector<int>>& nums, int i, int p) {

        if(i >= n)
            return 0;

        if(dp[i][p + 1] != -1)
            return dp[i][p + 1];

        int take = 0;

        if(p == -1 || nums[i][0] > nums[p][1]) {
            take = 1 + solve(nums, i + 1, i);
        }

        int skip = solve(nums, i + 1, p);

        return dp[i][p + 1] = max(take, skip);
    }
    
    int findLongestChain(vector<vector<int>>& pairs) {
          n = pairs.size();

        sort(pairs.begin(),pairs.end());

        memset(dp, -1, sizeof(dp));

        return solve(pairs, 0, -1);
        
    }
};
