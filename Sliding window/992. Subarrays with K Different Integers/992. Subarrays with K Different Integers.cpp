class Solution {
public:
// yhn par hum subarray jo <=k wale ke liye calcultae karenge
   int SlidingWindow(vector<int>& nums, int k) {

    int n = nums.size();
    int i=0;
    int j=0;
    int count=0;

    unordered_map<int,int>mp;

    while(j<n){
        mp[nums[j]]++;

        while(mp.size()>k)
        {
            // shrink window
            mp[nums[i]]--;
            if(mp[nums[i]] ==0)
            {
                mp.erase(nums[i]);
            }
            i++;
        }
        count+=(j-i+1); 
        //ye j tak point hone wale sab array nikal dega
        j++;
    }
    return count;
        
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {

        return SlidingWindow(nums,k)-SlidingWindow(nums,k-1);
        
    }
};
