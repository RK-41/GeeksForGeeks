//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int mod = 1e9+7;
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        // 14.09.23 potd
        
        vector<vector<int>> dp(n+1, vector<int>(sum+1,0));
        // the sub-index of dp represents sum
        
        // there's only one way to achieve a sum of 0, which is by choosing an empty subset
        dp[0][0] = 1;
        
        for(int i=1; i<=n; i++){
            for(int j=0; j<=sum; j++){
                int ans = dp[i-1][j];
                if(j-arr[i-1] >= 0)
                    ans += dp[i-1][j - arr[i-1]];
                
                dp[i][j] = ans%mod;
            }
        }
        
        return dp[n][sum];
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends