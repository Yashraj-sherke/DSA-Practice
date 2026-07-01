class Solution {
public:
    int maxProduct(vector<int>& nums) {

        int n= nums.size();
        int max_pro=nums[0];

        for(int i=0;i<n;i++)
        {
            int Pro=1;
            for(int j=0;j<n;j++)
            {
                Pro*=nums[j];

                max_pro=max(Pro,max_pro);

            }
        }

        return max_pro;

        
    }
};


// Optimal
