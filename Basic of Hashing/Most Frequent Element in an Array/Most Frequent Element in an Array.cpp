class Solution {
  public:
    int mostFreqEle(vector<int>& arr) {
        unordered_map<int, int> freq;
        int maxFreq = 0;
        int element = -1;

        // Count frequency of each element
        for (int i = 0; i < arr.size(); i++) {
            freq[arr[i]]++;
        }

        // Find the element with the highest frequency
        for (auto &it : freq) {
            if (it.second > maxFreq) {
                maxFreq = it.second;
                element = it.first;
            }
        }

        return element;
    }
};
