//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int editDistance(string str1, string str2) {
        // Code here
        // 10.03.25 (potd)
        int n=str1.size(), m=str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1,0));
        
        for(int i=0; i<=n; i++){
            dp[i][0] = i;
        }
        for(int j=0; j<=m; j++){
            dp[0][j] = j;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = dp[i-1][j-1];
                else
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
            }
        }
        
        return dp[n][m];
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        string s1;
        getline(cin, s1);
        string s2;
        getline(cin, s2);
        Solution ob;
        int ans = ob.editDistance(s1, s2);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends