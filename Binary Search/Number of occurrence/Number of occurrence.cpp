class Solution {
  public:
    int countFreq(vector<int>& arr, int target) {
        int n = arr.size();
        
        // First Occurrence
        int start = 0, end = n - 1, ansFirst = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                ansFirst = mid;
                end = mid - 1; // left me search
            } 
            else if (arr[mid] < target) {
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        
        // Last Occurrence
        start = 0; 
        end = n - 1; 
        int ansLast = -1;
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == target) {
                ansLast = mid;
                start = mid + 1; // right me search
            } 
            else if (arr[mid] < target) {
                start = mid + 1;
            } 
            else {
                end = mid - 1;
            }
        }
        
        if (ansFirst == -1) return 0; // target not found
        return ansLast - ansFirst + 1;
    }
};
