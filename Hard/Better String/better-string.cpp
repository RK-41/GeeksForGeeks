//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Function to count distinct subsequences using DP
    int countDistinctSub(const string& str){
        const int MOD = 1000000007;
        int n = str.size();
        
        // Array to store the last occurrence index of each character
        int lastOccurr[256];
        memset(lastOccurr, -1, sizeof(lastOccurr));
        
        // DP array to store count of distict subsequences
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        // base case: empty string has one subsequence
        
        // Iterating through each char of the string 
        for(int i=1; i<=n; i++){
            // Calculating count based on the recurrence relation
            dp[i] = (2 * dp[i-1])%MOD;
            
            // Subtracting count of subsequence ending atthe last occurrence of the current character
            if(lastOccurr[str[i-1]] != -1){
                dp[i] = (dp[i] - dp[lastOccurr[str[i-1]] - 1] + MOD) % MOD;
                
            }
            
            // Updating last occurrence index of the current character
            lastOccurr[str[i-1]] = i;
        }
        
        // Returning the final count of distinct subseqneces
        return dp[n];
    }
    // Function to find the better string based on distinct subsequences count
    string betterString(string str1, string str2) {
        // code here
        // 15.11.23 potd
        
        // Counting distinct subseqneces of each string
        int count1 = countDistinctSub(str1);
        int count2 = countDistinctSub(str2);
        
        // Comparing counts and returning the better string
        return (count1 >= count2) ? str1 : str2;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends