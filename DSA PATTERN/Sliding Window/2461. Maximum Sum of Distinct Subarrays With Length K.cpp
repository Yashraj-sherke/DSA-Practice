
// Brute Force Approch
class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        long long ans = 0;

        int n = nums.size();

    for(int i=0;i<=n-k;i++)
    {
    long long sum=0;
    unordered_set<int> st;

    for(int j=i;j<i+k;j++)
    {
        sum+=nums[j];
        st.insert(nums[j]);
    }

    if(st.size()==k)
    {
        ans=max(ans,sum);
    }
}
return ans;
        
    }
};
