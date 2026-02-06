class Solution {
public:
    int n;
    long long dp[100005][2];

    long long solve(int idx, vector<int>& nums, bool flag) {
        if (idx >= n)
            return 0;

        if (dp[idx][flag] != -1)
            return dp[idx][flag];

        // Skip
        long long skip = solve(idx + 1, nums, flag);

        // Take
        long long val = nums[idx];
        if (!flag) val = -val;

        long long take = solve(idx + 1, nums, !flag) + val;

        return dp[idx][flag] = max(skip, take);
    }

    long long maxAlternatingSum(vector<int>& nums) {

        n = nums.size();

        memset(dp, -1, sizeof(dp));

        return solve(0, nums, true);
    }
};
