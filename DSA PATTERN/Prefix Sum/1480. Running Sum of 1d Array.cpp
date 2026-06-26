class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {

        int n= nums.size();

        vector<int>Prefix(n);

        Prefix[0]=nums[0];

        for(int i=1; i < n; i++)
        {
            Prefix[i]=Prefix[i-1]+nums[i];
        }

        return Prefix;
        
    }
};
