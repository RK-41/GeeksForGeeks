//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalCount(string str){
	    // Code here
	    // 29.01.24 potd
	    vector<vector<int>> dp(1000, vector<int>(str.size(), -1));
	    return tc(0, 0, str, dp);
	}
	
	int tc(int sum, int i, string &s, vector<vector<int>>& dp){
	    if(i==s.size())   return 1;
	    
	    if(dp[sum][i] != -1)    return dp[sum][i];
	    
	    int ans=0, curr=0;
	    
	    for(int j=i; j<s.size(); j++){
	        curr += (s[j]-'0');
	        if(curr >= sum){
	            ans += tc(curr, j+1, s, dp);
	        }
	    }
	    
	    return dp[sum][i] = ans;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends