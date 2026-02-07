class Solution {
public:
    int n;
    int dp[2501][2502]; // p+1 used, so size +1

    int solve(vector<int>& nums, int i, int p) {

        if(i >= n)
            return 0;

        if(dp[i][p + 1] != -1)
            return dp[i][p + 1];

        int take = 0;

        if(p == -1 || nums[i] > nums[p]) {
            take = 1 + solve(nums, i + 1, i);
        }

        int skip = solve(nums, i + 1, p);

        return dp[i][p + 1] = max(take, skip);
    }

    int lengthOfLIS(vector<int>& nums) {

        n = nums.size();

        memset(dp, -1, sizeof(dp));

        return solve(nums, 0, -1);
    }
};
