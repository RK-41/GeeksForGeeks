//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    int max_courses(int n, int total, vector<int> &cost)
    {
        //Code Here
        // 15.01.24 potd
        // DP
        vector<vector<int>> dp(n+1, vector<int>(total+1, -1));
        return solve(0, cost, total, n, dp);
    }
    
    int solve(int i, vector<int>& cost, int total, int n, vector<vector<int>>& dp){
        if(total<=0 || i==n)    return 0;
        
        // If entry already esixts,
        if(dp[i][total] != -1)  return dp[i][total];
        
        int a=0, b=0;
        
        // Case when we can by the course and we actually but the course
        if(cost[i] <= total){
            a = 1 + solve(i+1, cost, floor(total-cost[i]*0.1), n, dp);
        }
        
        // Case when we don't by the course
        b = solve(i+1, cost, total, n, dp);
        
        dp[i][total] = max(a, b);
        
        return dp[i][total];
    }
};


//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        vector<int> arr(n);
        for(int i=0;i<n;i++) cin>>arr[i];
        Solution ob;
        cout<<ob.max_courses(n,k,arr)<<endl;
    }
}
// } Driver Code Ends