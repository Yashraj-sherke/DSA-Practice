class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

    //    isko previous problem me convert kar lo means odd ko 1 bana do aur even ko 0 
    
        unordered_map<int, int> prefixCount;
        prefixCount[0] = 1; // base case
        
        int sum = 0;
        int count = 0;
        
        for (int num : nums) {
            // Increase sum if number is odd
            sum += (num % 2);

            // If (sum - k) exists, add its count
            if (prefixCount.find(sum - k) != prefixCount.end()) {
                count += prefixCount[sum - k];
            }
            
            // Update prefix sum count
            prefixCount[sum]++;
        }
        return count;
        
    }
};
