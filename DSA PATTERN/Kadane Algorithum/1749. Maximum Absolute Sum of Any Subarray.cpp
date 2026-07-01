class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();

        int maxSum=nums[0];

        int currSum=nums[0];

        for(int i=1;i<n;i++)
        {
            currSum=max(nums[i],currSum+nums[i]);

            maxSum= max(currSum,maxSum);
        }


          int minSum=nums[0];

         currSum=nums[0];

        for(int i=1;i<n;i++)
        {
            currSum=min(nums[i],currSum+nums[i]);

            minSum= min(currSum,minSum);
        }


        return max(abs(maxSum),abs(minSum));



        
    }
};
