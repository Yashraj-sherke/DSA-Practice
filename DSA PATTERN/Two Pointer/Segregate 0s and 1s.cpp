class Solution {
public:
    void segregate0and1(vector<int> &arr) {
        int n = arr.size();
        // BRUTE APPROCH
        // int count0 = 0;

        // for(int i = 0; i < n; i++) {
        //     if(arr[i] == 0) {
        //         count0++;
        //     }
        // }

        // for(int i = 0; i < count0; i++) {
        //     arr[i] = 0;
        // }

        // for(int i = count0; i < n; i++) {
        //     arr[i] = 1;
        // }
        
        
        int start=0;
        int end= n-1;
        
        while(start<end)
        {
            if(arr[start]==0 )
            {
                start++;
            }
            else if(arr[end]==1)
            {
                end--;
            }
            else
            {
             swap(arr[start], arr[end]);
             start++;
             end--;
            }
           
        }
    }
};
