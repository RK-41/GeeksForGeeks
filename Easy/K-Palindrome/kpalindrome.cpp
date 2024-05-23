//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int kPalindrome(string str, int n, int k)
    {
        // code here
        // 23.05.24 potd
        vector<vector<int>> memo(n, vector<int>(n,-1));
        
        return minDeletions(0, n-1, str, memo) <= k;
    }
    
    int minDeletions(int l, int r, const string& str, vector<vector<int>>& memo){
        if(l >= r)  return 0;
        
        if(memo[l][r] != -1)    return memo[l][r];
        
        if(str[l] == str[r])
            memo[l][r] = minDeletions(l+1, r-1, str, memo);
        else
            memo[l][r] = 1 + min(minDeletions(l+1, r, str, memo), minDeletions(l, r-1, str, memo));
            
        return memo[l][r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, k;
        cin>>n>>k;
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.kPalindrome(str, n, k)<<endl;
    }
    return 0;
}
// } Driver Code Ends