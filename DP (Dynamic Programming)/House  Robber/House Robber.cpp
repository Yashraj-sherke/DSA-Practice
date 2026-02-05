class Solution {
public:

    int find(int index, vector<int>& nums, vector<int>& dp) {

        if(index >= nums.size())
            return 0;

        if(dp[index] != -1)
            return dp[index];

        return dp[index] = max(
            nums[index] + find(index + 2, nums, dp),
            find(index + 1, nums, dp)
        );
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        vector<int> dp(n, -1);

        return find(0, nums, dp);
    }
};
