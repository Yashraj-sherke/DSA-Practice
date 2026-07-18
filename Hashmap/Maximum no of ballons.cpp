class Solution {
public:
    int maxNumberOfBalloons(string text) {

        int count[26]={0};
        for(char c:text){
            count[c-'a']++;
        }

       
        int result = count['b' - 'a']; 
        result = min(result, count['a' - 'a']);
        result = min(result, count['l' - 'a'] / 2); 
        result = min(result, count['o' - 'a'] / 2); 
        result = min(result, count['n' - 'a']);
        return result;
        
    }
};


class Solution {
public:
    int maxNumberOfBalloons(string text) {
        // Count characters in the input text
        unordered_map<char, int> textCount;
        for (char c : text) {
            textCount[c]++;
        }

        // Count characters in the target word
        string target = "balloon";
        unordered_map<char, int> targetCount;
        for (char c : target) {
            targetCount[c]++;
        }

        // Find the minimum number of complete "balloon"s we can form
        int result = INT_MAX;
        for (auto& [ch, demand] : targetCount) {
            int supply = textCount.count(ch) ? textCount[ch] : 0;
            result = min(result, supply / demand);
        }
        return result;
    }
};
