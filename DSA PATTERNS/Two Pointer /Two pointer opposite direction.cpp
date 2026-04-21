
1 Two Sum 
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

    // vector<int>v;

    // int n= nums.size();

    // for(int i=0;i<n-1;i++)
    // {
    //     for(int j=i+1;j<n;j++)
    //     {
    //         if(nums[i]+nums[j]== target)
    //         {
    //             return {i,j};
    //         }
    //     }
    // }


      int n = nums.size();

        // Step 1: store value + index
        vector<pair<int,int>> v;
        for(int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        // Step 2: sort by value
        sort(v.begin(), v.end());

        // Step 3: two pointer
        int i = 0, j = n - 1;

        while(i < j) {
            int sum = v[i].first + v[j].first;

            if(sum == target) {
                return {v[i].second, v[j].second}; // original indices
            }
            else if(sum < target) {
                i++;
            }
            else {
                j--;
            }
        }

        return {};
  
        
    }
};
