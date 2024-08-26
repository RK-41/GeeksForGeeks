//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    int wildCard(string pattern, string str) {
        // code here
        // 26.08.24 potd
        int p = pattern.size(), s=str.size();
        vector<vector<int>> dp(s+1, vector<int>(p+1,0));
        dp[0][0] = 1;
        
        for(int i=0; i<p; i++){
            if(pattern[i] == '*')
                dp[0][i+1] = dp[0][i];
        }
        
        for(int i=1; i<=s; i++){
            for(int j=1; j<=p; j++){
                if(pattern[j-1] == str[i-1] || pattern[j-1] == '?')
                    dp[i][j] = dp[i-1][j-1];
                else if(pattern[j-1] == '*')
                    dp[i][j] = dp[i][j-1] | dp[i-1][j];
            }
        }
        return dp.back().back();
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends