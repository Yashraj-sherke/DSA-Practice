class Solution {
  public:
    int maximumSumSubarray(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        int i = 0, j = 0;
        int sum = 0;
        int maxi = INT_MIN;
        
        while (j < n) {
            sum += arr[j];  // add current element
            
            // If window size < k, expand the window
            if (j - i + 1 < k) {
                j++;
            }
            // If window size == k, check max and slide
            else if (j - i + 1 == k) {
                maxi = max(maxi, sum);
                sum -= arr[i]; // remove the first element of the window
                i++;
                j++;
            }
        }
        return maxi;
        
    }
};
