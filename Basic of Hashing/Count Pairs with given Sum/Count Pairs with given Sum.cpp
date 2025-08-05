class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        unordered_map<int, int> freq;
        int count = 0;

        for (int i = 0; i < arr.size(); i++) {
            int complement = target - arr[i];

            // Step 1: If complement is already in map, add its frequency to count
            if (freq.find(complement) != freq.end()) {
                count += freq[complement];
            }

            // Step 2: Add current element to map
            freq[arr[i]]++;
        }

        return count;
    }
};
