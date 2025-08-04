class Solution {
  public:
    void reverseArray(vector<int> &arr,int start,int end) {
        
        // base case 
        // 
        // int start = arr[0];
        // int end = arr.size()-1;
        
        if(start>=end)
        {
          return; 
        }
        
        swap(start,end);  
        
        reverseArray(arr,start+1,end-1);
    }
};
