class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        // brute approch

        // int n = nums.size();

        // int count =0;

        // for(int i =0;i<n;i++)
        // {
        //     int sum =0;
        //     for(int j=i;j<n;j++)
        //     {
        //         sum+=nums[j];     

        //          if(sum == goal)
        //         {
        //             count+=1;
        //         }

        //     }
           
        // }
        // return count;

        // optimal approch 1

        // int  n= nums.size();
        // unordered_map<int, int> mp;
        
        // int count   = 0;
        // int currSum = 0;
        // mp[0] = 1;
        // for(int &num : nums) {
            
        //     currSum += num;

        //     if(mp.find(currSum - goal) != mp.end()) {
        //         count += mp[currSum - goal];
        //     }
            
        //     mp[currSum]++;
            
            
        // }
        
        // return count;

        // approch 2
         int prefix_zeros = 0;
        int window_sum = 0;
        int count = 0;
        
        int i = 0, j = 0;
        
        while(j < nums.size()) {
            window_sum += nums[j];
            
            while (i < j && (nums[i] == 0 || window_sum > goal)) {
                if (nums[i] == 1) {
                    prefix_zeros = 0;
                } else {
                    prefix_zeros += 1;
                }
                
                window_sum -= nums[i];
                i++;
            }
            
            if (window_sum == goal) {
                count += 1 + prefix_zeros;
            }
            j++;
        }
        
        return count;

        
    }
};
