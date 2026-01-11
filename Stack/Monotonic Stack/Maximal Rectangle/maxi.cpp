class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxArea = 0;

    heights.push_back(0);   

    for (int i = 0; i < heights.size(); i++) {

        while (!st.empty() && heights[i] < heights[st.top()]) {
            int height = heights[st.top()];
            st.pop();

            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;

            maxArea = max(maxArea, height * width);
        }

        st.push(i);
    }

    heights.pop_back(); 
    return maxArea;
}

    int maximalRectangle(vector<vector<char>>& matrix) {

        int ans =0;
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int>height(col,0);

        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(matrix[i][j]=='0')
                {
                    height[j]=0;
                }
                else{
                    height[j]+=1;
                }
            }

            ans = max(ans ,largestRectangleArea(height));

            
        }
        return ans;
        
    }
};
