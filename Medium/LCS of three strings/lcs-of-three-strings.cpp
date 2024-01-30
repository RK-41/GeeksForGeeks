//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:

        int LCSof3 (string A, string B, string C, int n1, int n2, int n3)
        {
            // your code here
            // 30.01.24 potd
            vector<vector<vector<int>>> dp(n1, vector<vector<int>>(n2, vector<int>(n3, -1)));
            return solve(A,B,C,0,0,0,n1,n2,n3,dp);
        }
        
        int solve(string a, string b, string c, int i, int j, int k, int n1, int n2, int n3, vector<vector<vector<int>>>&dp){
            if(i==n1 || j==n2 || k==n3) return 0;
            
            if(dp[i][j][k] != -1)   return dp[i][j][k];
            
            if(a[i]==b[j] && a[i]==c[k]){
                return dp[i][j][k] = 1 + solve(a,b,c,i+1,j+1,k+1,n1,n2,n3,dp);
            }
            
            int aa = solve(a,b,c,i+1,j,k,n1,n2,n3,dp);
            int bb = solve(a,b,c,i,j+1,k,n1,n2,n3,dp);
            int cc = solve(a,b,c,i,j,k+1,n1,n2,n3,dp);
            
            return dp[i][j][k] = max({aa,bb,cc});
        }
};


//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; cin >> n1 >> n2 >> n3;
        string A, B, C; cin >> A >> B >> C;
        Solution obj;
        cout << obj.LCSof3 (A, B, C, n1, n2, n3) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends