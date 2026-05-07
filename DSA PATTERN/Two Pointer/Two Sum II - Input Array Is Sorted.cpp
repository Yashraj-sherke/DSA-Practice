class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
    //  BRUTE METHOD:
        // int n= numbers.size();
        // vector<int>ans;

        // for(int i=0;i<n-1;i++)
        // {
        //     for(int j=i+1;j<n;j++)
        //     {
        //         if(numbers[i]+numbers[j]==target)
        //         {
        //             ans.push_back(i+1);
        //             ans.push_back(j+1);

        //         }
        //     }
        // }

        // return ans;

        int n= numbers.size();

        int start=0;
        int end=n-1;
        vector<int>ans;

        while(start<end)
        {
            if(numbers[start]+numbers[end]==target)
            {
                ans.push_back(start+1);
                ans.push_back(end+1);
                break;
            }
            else if(numbers[start]+numbers[end]>target)
            {
                end--;
            }
            else
            {
                start++;
            }
        }

        return ans;
        
    }
};
