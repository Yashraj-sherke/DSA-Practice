class Solution {
public:
    int findMin(vector<int>& nums) {

        int s = 0;
        int e = nums.size()-1;

        while(s<e)
        {
            
        //    Agar puri sorrted array ho to 
            if(nums[s]<nums[e])
            {
                return nums[s];
            }

            int m = s+(e-s)/2;
          
            if(nums[m]>=nums[s])
            {
                s=m+1;
            }
            else{
                e=m;
            }
        }
        return nums[s];
        
    }
};
