//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:	
	int distinctSubsequences(string s)
	{
	    // Your code goes here
	    // 02.10.23 potd
	    // Approach: DP
	   
	    // Initialize a modulo value to prevent integer overflow 
	    int mod = 1e9+7;
	    int n = s.size();
	    
	    // um: An u.m. to store the last seen index of each char in the string
	    unordered_map<char,int> um;
	    
	    // dp: a vector to store the no. of distinct subsequences of 's' of length 'i'
	    vector<int> dp(n+1);
	    
	    // Initialize dp[0] as 1 because there's one empty subsequence
	    dp[0] = 1;
	    
	   
	    // Loop through each char in the input string
	    for(int i=1; i<=n; i++){
	        
	        // Calculating dp[i] as twice the value of dp[i-1], modulo 'mod'
	        dp[i] = (2*dp[i-1])%mod;
	        
	        // Getting curr char
	        char ch = s[i-1];
	        
	        // Checking if 'ch' has been seen before (its last occurrence)
	        if(um[ch]){
	            // If 'ch' has been seen before, subtracting dp[j-1] from dp[i]
	            // dp[j-1] is the no. of subsequences that ended at previous occurrence of 'ch'
	            int j = um[ch];

	            dp[i] = (dp[i] - dp[j-1] + mod)%mod;
	        }
	        
	        // Updating the last seen of 'ch'
	        um[ch] = i;
	    }
	    
	    // Returning  the final value stored at idx 'n' which is the no. of distinct subsequence
	    // of the input string 's'
	    return dp[n];
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

        Solution ob;
   		cout << ob.distinctSubsequences(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends