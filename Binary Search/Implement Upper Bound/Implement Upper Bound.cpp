class Solution {
  public:
    int upperBound(vector<int>& arr, int target) {
        // code here
        
        int ans = arr.size();
        
        int start=0;
        int end=arr.size()-1;
        
        while(start<=end){
            int mid= start+(end-start)/2;
            
            if(arr[mid]>target)
            {
                ans= mid;
                
                end= mid-1; //Left side chek karnge khintargt se koi aur tobada nhi hai
            }
            else{
                start=mid+1;
            }
        }
        return ans;
        
    }
};
