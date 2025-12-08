class Solution {
  public:
    string matrixChainOrder(vector<int> &arr) {
        // code here
        // 27.01.24 potd
        // 08.12.25 potd
        int n = arr.size();
        vector<vector<pair<int,string>>> dp(n+1, vector<pair<int,string>>(n+1, {-1, ""}));
        return solve(1, n-1, arr, dp).second;
    }
    pair<int,string> solve(int i, int j, vector<int> p, vector<vector<pair<int,string>>>&dp){
        if(i==j)    return {0, string(1, static_cast<char>('A' + i-1))};
        
        if(dp[i][j].first != -1)    return dp[i][j];
        
        int mini = 1e9;
        string temp="";
        for(int k=i; k<j; k++){
            pair<int,string> p1 = solve(i, k, p, dp);
            pair<int,string> p2 = solve(k+1, j, p, dp);
            
            int total = p[i-1]*p[k]*p[j] + p1.first + p2.first;
            if(total<mini){
                temp="(" + p1.second + p2.second + ")";
                mini=total;
            }
        }
        
        return dp[i][j] = {mini, temp};
    }
};
