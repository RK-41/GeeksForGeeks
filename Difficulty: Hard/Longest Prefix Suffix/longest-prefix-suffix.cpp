
// User function template for C++

class Solution {
  public:
    int getLPSLength(string &str) {
        // Your code goes here
        // 08.08.25 (potd)
        int ans=0, n=str.size(), i=1, j=0;
        vector<int> len(n);
        
        while(i<n){
            if(str[i] == str[j])
                len[i++] = ++j;
            else {
                if(j>0)
                    j = len[j-1];
                else
                    i++;
            }
        }
        
        return len[n-1];
    }
};
