class Solution {
  public:
    bool wildCard(string &txt, string &pat) {
        // code here
        // 12.11.25 potd
        int p = pat.size(), s=txt.size();
        vector<vector<int>> dp(s+1, vector<int>(p+1,0));
        dp[0][0] = 1;
        
        for(int i=0; i<p; i++){
            if(pat[i] == '*')
                dp[0][i+1] = dp[0][i];
        }
        
        for(int i=1; i<=s; i++){
            for(int j=1; j<=p; j++){
                if(pat[j-1] == txt[i-1] || pat[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(pat[j-1] == '*')
                    dp[i][j] = dp[i][j-1] | dp[i-1][j];
            }
        }
        return dp.back().back();
    }
};