class Solution {
public:
    int maxSubArray(vector<int>& nums) {

       int max_sum=nums[0];
       int sum=0;

       for(int num:nums)
       {
        sum+=num;
        max_sum=max(max_sum,sum);


        if(sum<0)
        {
            sum=0;
        }

       }
       return max_sum;
        
        
    }
};
