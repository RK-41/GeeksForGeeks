//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        // 24.08.24 potd
        int n = wt.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1,-1));
        
        return calculate(W, wt, val, 0, dp);
    }
    
    int calculate(int W, vector<int>& wt, vector<int>& val, int idx, vector<vector<int>>& dp){
        if(idx == wt.size())    return 0;
        if(W < 0)   return 0;
        if(dp[idx][W] != -1)    return dp[idx][W];
        
        int take=0;
        if(wt[idx] <= W){
            take = val[idx] + calculate(W-wt[idx], wt, val, idx+1, dp);
        }
        
        int notTake = calculate(W, wt, val, idx+1, dp);
        
        return dp[idx][W] = max(take, notTake);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends