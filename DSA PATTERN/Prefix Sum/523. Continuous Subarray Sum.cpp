// Brute Force
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        int n= nums.size();

        for(int i=0;i<n-1;i++)
        {
            int sum=nums[i];

            for(int j=0;j<n;j++){
                sum+=nums[j];
                if(sum%k==0)
                {
                    return true;
                }
            }

        }
        return false;
        
    }
};


// Optimal Approch
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        mp[0] = -1;

        int prefix = 0;

        for(int i = 0; i < nums.size(); i++) {

            prefix += nums[i];

            int rem = prefix % k;

            if(mp.find(rem) != mp.end()) {

                if(i - mp[rem] >= 2)
                    return true;
            }
            else {
                mp[rem] = i;
            }
        }

        return false;
    }
};
