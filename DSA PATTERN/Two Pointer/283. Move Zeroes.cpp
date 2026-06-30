class Solution {
public:
    void moveZeroes(vector<int>& arr) {

        int n =arr.size();
         vector<int>temp(n);
        
        int j=0;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]!=0)
            {
               temp[j]=arr[i];
               j++;
            }
           
        }
        
        while (j < n) {
        temp[j] = 0;
        j++;
                   }
        
        
        arr=temp;
        
    }
};
