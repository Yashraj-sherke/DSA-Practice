// Brute Approch
class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n= nums.size();

        for(int i=0;i<n;i++)
        {
            int Left=0;

            for(int j=0;j<i;j++)
            {
                Left+=nums[j];
            }

            int Right=0;
            for(int k=i+1;k<n;k++)
            {
                Right+=nums[k];
            }

            if(Left==Right)
            {
                return i;
            }
        }
        return -1;
        
    }
};

// Optimal
class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int total = 0;

        for (int num : nums) {
            total += num;
        }

        int Left = 0;

        for (int i = 0; i < nums.size(); i++) {

            int Right = total - Left - nums[i];

            if (Left == Right) {
                return i;
            }

            Left += nums[i];
        }

        return -1;
    }
};
