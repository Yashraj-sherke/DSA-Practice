
// Brute Approch 
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();
        int count = 0;

        for (int i = 0; i < n; i++) {

            int sum = 0;

            for (int j = i; j < n; j++) {

                sum += nums[j];

                if (sum % k == 0)
                    count++;
            }
        }

        return count;
    }
};

// Optimal Approch

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();

        unordered_map<int,int>mp;
        mp[0]=1;
        int sum=0;
        int result=0;

        for(int i=0;i<n;i++)
        {
            sum+=nums[i];

            int rem = sum%k;

            if(rem<0)
            {
                rem+=k;
            }
            if(mp.find(rem)!=mp.end())
            {
                result+=mp[rem];
            }

            mp[rem]++;
        }  

        return result;
    }
};
