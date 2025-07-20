class Solution {
public:
    int totalFruit(vector<int>& fruits) {

        int n = fruits.size();

        // Brute approch

        // int maxlen =0;

        // for(int i=0;i<n;i++){
        //     unordered_map<int,int>freq;

        //     for(int j=i;j<n;j++)
        //     {
        //         freq[fruits[j]]++;

        //         if(freq.size() <= 2)
        //         {
        //             maxlen= max(maxlen,j-i+1);

        //         }
        //         else{
        //             break;
        //         }

        //     }
        // }
        // return maxlen;

        // Sliding Window

        int start = 0;
        int end =0;

        int maxlen=0;
        unordered_map<int,int>freq;

        while(end<n)
        {
            freq[fruits[end]]++;

            // violetion condtion

            while(freq.size() > 2){
                freq[fruits[start]]--;

                if(freq[fruits[start]]==0) freq.erase(fruits[start]);
                start++;
            }
            maxlen = max(maxlen,end-start+1);
            end++;
        }

        return maxlen;

        
    }
};
