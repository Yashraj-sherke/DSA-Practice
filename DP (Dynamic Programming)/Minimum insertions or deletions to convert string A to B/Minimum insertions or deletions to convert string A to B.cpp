class Solution {
public:
    int n, m;
    int t[1001][1001];

    int solve(string &word1,string &word2,int i,int j)
    {
        if(i>=n || j>=m)
            return 0;

        if(t[i][j]!=-1)
            return t[i][j];

        if(word1[i]==word2[j])
            return t[i][j]=1+solve(word1,word2,i+1,j+1);

        return t[i][j]=max(
            solve(word1,word2,i+1,j),
            solve(word1,word2,i,j+1)
        );
    }

    int minDistance(string word1, string word2) {

        n=word1.length();
        m=word2.length();
        memset(t,-1,sizeof(t));

        int lcs = solve(word1,word2,0,0);

        return n+m - 2*lcs;   //kyoki dono word se delete krna hai 
    }
};
