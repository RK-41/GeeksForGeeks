class Solution {
  public:
    int sumSubstrings(string &s) {
        // code here
        // 24.05.25 potd
        int n = s.size(), place = 1, sum = 0;
        
        for(int i=n-1; i>=0; i--){
            int d = s[i] - '0';
            sum += d * (i+1) * place;
            place = place * 10 + 1;
        }
        
        return sum;
    }
};