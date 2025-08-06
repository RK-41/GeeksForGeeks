//User function template for C++

class Solution {
  public:
    int romanToDecimal(string &str) {
        // code here
        // 06.08.25  (POTD)
        
        // rtoi: roman to integer
        unordered_map<char,int> rtoi = {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int ans = 0;
        
        for(int i=0; i<str.size(); i++){
            // If something like IX, IL, CD, etc. is encountered
            //  subtract the current Roman value and continue
            if(i<str.size()-1 && rtoi[str[i]]<rtoi[str[i+1]]){
                ans -= rtoi[str[i]];
                continue;
            }
            ans += rtoi[str[i]];
            // cout<<s<<" "<<ans<<endl;
        }
        
        return ans;
    }
};
