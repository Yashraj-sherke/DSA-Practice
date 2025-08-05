class Solution {
  public:
    vector<vector<int>> countFreq(vector<int>& arr) {
        // code here
        unordered_map<int,int>freq;
        
        for(int it : arr)
        {
            freq[it]++;
        }
        
        vector<vector<int>>result;
        
        // Push key-value pairs into 2D vector
        for (auto &entry : freq) {
            result.push_back({entry.first, entry.second});
        }

        return result;
    }
};
