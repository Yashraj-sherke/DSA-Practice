class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int> freq(26, 0); // Frequency of each character
        int start = 0, maxFreq = 0, maxLen = 0;

        for (int end = 0; end < n; end++) {
            freq[s[end] - 'A']++;
            maxFreq = max(maxFreq, freq[s[end] - 'A']);

            // Violation: replacements required > k
            while ((end - start + 1) - maxFreq > k) {
                freq[s[start] - 'A']--;
                start++;
            }

            maxLen = max(maxLen, end - start + 1);
        }
        return maxLen;
        
    }
};
