//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int dp[100001][2], m=1e9+7;
	
	int TotalWays(int n)
	{
	    // Code here
	    // 05.01.24 potd
	    memset(dp, 0, sizeof dp);
	    long long x = fxn(n, 0)%m;
	    
	    return (x*x)%m;
	}
	
	int fxn(int n, bool x){
	    if(!n)  return 1;
	    
	    if(dp[n][x])    return dp[n][x];
	    
	    if(x)   return dp[n][x] = fxn(n-1, 0)%m;
	    
	    return dp[n][x] = (fxn(n-1, 1)%m + fxn(n-1, 0)%m)%m;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends