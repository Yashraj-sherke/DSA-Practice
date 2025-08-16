class Solution {
public:
    int maximum69Number (int num) {

        vector<int>digits;
        string s = to_string(num);

        for(char c:s)
        {
            digits.push_back(c-'0');
        }
 //  Sabse phele to isme me ye galti kar rha tha ki vector me i jo hai wo sidhe digit ko point karta hai wo index nhi hota jisse digit[i]= 9  karne par wo galt elemnet
      // ko access karega 
        // for(int i:digits)
        // {
        //     if(digits[i]==6)
        //     {
        //         digits[i]=9;
        //         break;
        //     }

        for(int i=0;i<digits.size();i++)
        {
            if(digits[i]==6)
            {
                digits[i]=9;
                break;
            }
        }

        // yhn par agar array to digits me convert karna hai to ans = 0 se intilasies karaao 
      // Ye multiply by 10 isliye karte hain kyunki naye digit ko right-most jagah shift karna hai.
        int ans = 0;
        for (int d : digits) {
         ans = ans * 10 + d;
         }
         return ans;
    
        
    }
};
