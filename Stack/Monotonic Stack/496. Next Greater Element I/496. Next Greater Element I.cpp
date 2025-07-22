class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        // Brute approch
         vector<int> ans;  

        for (int i = 0; i < nums1.size(); i++) {
            
            int nextGreater = -1;   // default value agar koi greater nahi mila
            bool startCheck = false; 

            
            for (int j = 0; j < nums2.size(); j++) {
                
                if (nums2[j] == nums1[i]) {
                    startCheck = true;   // yaha se next greater dhundhna start
                }
                else if (startCheck && nums2[j] > nums1[i]) {
                    nextGreater = nums2[j];  // pehla greater mila
                    break;  // ek baar mil gaya to aage dekhne ki zarurat nahi
                }
            }

            ans.push_back(nextGreater);  // result add kar diya
        }

        return ans;



        
    }
};
