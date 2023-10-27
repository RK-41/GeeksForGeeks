//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int minimumNumberOfDeletions(string S) { 
        // code here
        // 27.10.23 potd
        
        // Reverse the given string then, find the LCS
        string r = S;
        reverse(r.begin(), r.end());
        int n = S.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        
        return S.size()-solve(0,0,S,r,dp);
    } 
    
    int solve(int i, int j, string &s, string &r, vector<vector<int>>& dp){
        if(i==s.size() || j==s.size())  return 0;
        
        if(dp[i][j] != -1)  return dp[i][j];
        
        int take = 0, notTake = 0;
        if(s[i] == r[j])
            take = 1+solve(i+1, j+1, s, r, dp);
            
        notTake = max(solve(i+1, j, s, r, dp), solve(i, j+1, s, r, dp));
        
        return dp[i][j] = max(take, notTake);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends