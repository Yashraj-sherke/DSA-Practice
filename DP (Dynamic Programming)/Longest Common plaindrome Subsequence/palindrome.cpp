class Solution {
public:
    int t[1001][1001];
    int LPS(string& s, int i, int j) {
        if(i > j)
            return 0;
        if(i == j)
            return 1;
        
        if(t[i][j] != -1)
            return t[i][j];
        if(s[i] == s[j])
            return t[i][j] = 2 + LPS(s, i+1, j-1);
        else
            return t[i][j] = max(LPS(s, i+1, j), LPS(s, i, j-1));
    }
    
    int longestPalindromeSubseq(string s) {
        int m = s.length();
        memset(t, -1, sizeof(t));
        
        return LPS(s, 0, m-1); //Approach-1
        
    }
};
