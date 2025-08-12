// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int target) {
        // code here
        int start = 0;
        int end = arr.size()-1;
        
        int ans =-1
        
        while(start<=end)
        {
            int mid = start+(end-start)/2;
            
            if(arr[mid]>=target)
            {
                ans = mid;
                end= mid-1;
               
                
            }
            else{
                 
                 start = mid+1;
            }
        }
        return ans;
    }
};
