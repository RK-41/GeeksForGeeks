//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#define vi std::vector<int>
#define vvi std::vector<vi>
#define ll long long int

class Solution {
  public:
    const int mod = 1e9+7;
    
    int countPartitions(int n, int d, vector<int>& arr) {
        // Code here
        // 24.05.24 potd
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        if(sum < d || (sum-d)%2 != 0) 
            return 0;
            
        // Required subset sum
        int req = (sum-d)/2;
        
        // DP Table
        vvi dp(n+1, vi(req+1, 0));
        
        // Base case: There's only one way to get sum 0 with no elements
        dp[n][0] = 1;
        
        // Populating the DP Table
        for(int idx=n-1; idx>=0; --idx){
            for(int tar=0; tar<=req; ++tar){
                ll leave = dp[idx+1][tar]%mod;
                ll pick = (tar >= arr[idx]) ? dp[idx+1][tar-arr[idx]]%mod : 0;
                
                dp[idx][tar] = (pick + leave)%mod;
            }
        }
        
        return dp[0][req];
    }
    
    // Recursive helper function for memoization
    ll help(int idx, int tar, int sum, int n, vi &arr){
        if(idx == n)
            return sum == tar;
            
        ll pick = help(idx+1, tar+arr[idx], sum, n, arr)%mod;
        ll leave = help(idx+1, tar, sum, n, arr)%mod;
        
        return (pick + leave)%mod;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
// } Driver Code Ends