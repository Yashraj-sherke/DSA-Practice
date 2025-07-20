class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        // Brute force


        // int length = INT_MIN;

        // for(int i=0; i<n; i++) {
        //     unordered_map<char,int> mp;
        //     for(int j=i; j<n; j++) {
        //         mp[s[j]]++;
        //         if(mp[s[j]] > 1) break;  // duplicate mila
        //         length = max(length, j - i + 1);
        //     }
        // }
        // return length;

        // Optimize approch-->Sliding window

        int i=0;
        int j=0;

        int ans=0;

        unordered_map<char,int>mp;

        while(j<n){
            mp[s[j]]++;


            // condtion violetion

            while(mp[s[j]] > 1)
            {
                mp[s[i]]--;

                if(mp[s[i]]==0) mp.erase(s[i]);
                i++;
            }
            // current window se ans

            ans = max(ans , j-i+1);
            j++;
        }
        return ans;

    }
};
