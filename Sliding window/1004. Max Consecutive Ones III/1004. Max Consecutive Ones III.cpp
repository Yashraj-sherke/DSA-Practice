class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        // Brute

        // int n = nums.size();
        // int maxLen = 0;

        // for (int i = 0; i < n; i++) {
        //     int zeroCount = 0;
        //     for (int j = i; j < n; j++) {
        //         if (nums[j] == 0) zeroCount++;

        //         // Agar zeroCount > k, subarray invalid ho gaya
        //         if (zeroCount > k) break;

        //         // Agar valid hai toh length update karo
        //         maxLen = max(maxLen, j - i + 1);
        //     }
        // }

        // return maxLen;

        // optimise 
        int n = nums.size();
    
        int start =0;
        int end =0;
        int maxLen =0;
       int zeroCount =0;

        while(end<n)
        {
           if(nums[end]==0) zeroCount++;

        //    window violetion

            while(zeroCount>k)
            {
                // shrink window
                if(nums[start]==0) zeroCount--;
                start++;

            }
            maxLen=max(maxLen,end-start+1);
            end++;

        }
        return maxLen;
    }
};
