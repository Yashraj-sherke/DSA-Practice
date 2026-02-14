class Solution {
public:

    int m,n;
    int solve(int i, int j ,vector<vector<int>>& obstacleGrid,vector<vector<int>>&t)
    {
        if(i<0 || i>=m|| j<0 || j>=n || obstacleGrid[i][j]==1){
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            return 1;
        }
        
        if(t[i][j]!=-1) return t[i][j];

        int right =solve(i,j+1,obstacleGrid,t);
        int down = solve(i+1,j,obstacleGrid,t);

        return t[i][j]= right+down;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

         m = obstacleGrid.size();
         n = obstacleGrid[0].size();

         vector<vector<int>>t(m+1,vector<int>(n+1,-1));

       return  solve(0,0,obstacleGrid,t);
        
    }
};
