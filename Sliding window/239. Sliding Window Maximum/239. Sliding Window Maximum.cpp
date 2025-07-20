class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {

        int n = nums.size();
        deque<int> q;   // Will store indices
        vector<int> ans;

        int i = 0, j = 0;
        while (j < n) {
            // Remove all elements smaller than current element from the back
            while (!q.empty() && nums[q.back()] < nums[j]) {
                q.pop_back();
            }
            q.push_back(j); // Add current index

            // Check if window size is less than k
            if (j - i + 1 < k) {
                j++;
            }
            // If window size hits k
            else if (j - i + 1 == k) {
                ans.push_back(nums[q.front()]); // front of deque is max
                // Remove if the element at front is going out of window
                if (q.front() == i) q.pop_front();
                i++;
                j++;
            }
        }
        return ans;
    }
};
