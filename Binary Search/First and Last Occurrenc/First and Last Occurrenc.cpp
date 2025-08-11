class Solution {
public:
    vector<int> find(vector<int>& arr, int x) {
        int n = arr.size();
        int start = 0, end = n - 1;
        int first = -1, last = -1;

        // First occurrence
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x) {
                first = mid;
                end = mid - 1; // search left
            }
            else if (arr[mid] < x) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        // Reset for last occurrence search
        start = 0; 
        end = n - 1;

        // Last occurrence
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (arr[mid] == x) {
                last = mid;
                start = mid + 1; // search right
            }
            else if (arr[mid] < x) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return {first, last};
    }
};
