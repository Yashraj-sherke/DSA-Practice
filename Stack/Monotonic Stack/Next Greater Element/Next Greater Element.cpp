class Solution {
  public:
    vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        int n = arr.size();
        
        // brute approch
        
        // vector<int>ans(n,-1);
        // for(int i =0;i<n-1;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(arr[j]>arr[i]){
        //             ans[i]=arr[j];
        //             break;
        //         }
        //     }
        // }
        // return ans;
        
        // optimize -->by stack kyoki j jo hai wo i pe depend hai
        
           vector<int> ans;
           stack<int> st;  // stack to store elements

           for (int i = n - 1; i >= 0; i--) {  // right se left traverse karenge
          if (st.empty())
          {
            ans.push_back(-1);
          }
        else if (!st.empty() && st.top() > arr[i]) 
        {
            ans.push_back(st.top());
        }
        else if (!st.empty() && st.top() <= arr[i])
        {
            while (!st.empty() && st.top() <= arr[i]) 
            {
                st.pop();
            }
            if (st.empty()) ans.push_back(-1);
            else ans.push_back(st.top());
        }
        st.push(arr[i]);
    }

    reverse(ans.begin(), ans.end());
    return ans;
        
        
    }
};
