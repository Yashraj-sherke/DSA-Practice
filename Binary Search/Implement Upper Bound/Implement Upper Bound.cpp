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


// Combine Templete 
#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int target, string mode) {
    int start = 0, end = arr.size() - 1;
    int ans = -1; // default for "not found"

    while (start <= end) {
        int mid = start + (end - start) / 2;

        if (mode == "search") {
            // NORMAL BINARY SEARCH
            if (arr[mid] == target) return mid;
            else if (arr[mid] < target) start = mid + 1;
            else end = mid - 1;
        }
        else if (mode == "lower") {
            // LOWER BOUND
            if (arr[mid] >= target) {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
        else if (mode == "upper") {
            // UPPER BOUND
            if (arr[mid] > target) {
                ans = mid;
                end = mid - 1;
            }
            else start = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};

    cout << "Normal Search (7): " << binarySearch(arr, 7, "search") << "\n";
    cout << "Lower Bound (6): " << binarySearch(arr, 6, "lower") << "\n";
    cout << "Upper Bound (6): " << binarySearch(arr, 6, "upper") << "\n";

    return 0;
}
