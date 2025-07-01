
class Solution {
public:
    int possibleStringCount(string word) {

        int n =word.length();
        // unordered_map<int,int>freq;

        // for(int i=0;i<n;i++){
        //     freq[word[i]]++;
        // }

        // int count=0;
        // int max_ele =0;
        

        // for(auto it:freq){
        //     if(it.second>count)
        //     {
        //         count=it.second;
        //         max_ele=it.first;
        //     }
        // }
        // if(count==1)
        // {
        //     return 1;
        // }
        // return count+1;
      int total = 1;
      for (int i = 0; i < n;) {
        int j = i;
        
        while (j < n && word[j] == word[i]) {
            j++;
        }
        int len = j - i;
        if (len > 1) {
            total += len - 1; 
        }
        i = j;
    }

    return total;
        



        
    }
};
