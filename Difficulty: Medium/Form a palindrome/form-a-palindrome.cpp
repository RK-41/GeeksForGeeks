//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int countMin(string str){
    //complete the function here
        // 27.07.24 potd
        int n = str.size();
        vector<vector<int>> memo(n, vector<int>(n,-1));
        
        return solve(memo, str, 0, n-1);
    }
    
  private:
    int solve(vector<vector<int>>& memo, const string& str, int i, int j){
        if(i >= j)
            return 0;
            
        if(memo[i][j] != -1)
            return memo[i][j];
            
        if(str[i] == str[j])
            memo[i][j] = solve(memo, str, i+1, j-1);
        else {
            int ans = INT_MAX;
            ans = min(ans, 1 + solve(memo, str, i+1, j));
            ans = min(ans, 1 + solve(memo, str, i, j-1));
            
            memo[i][j] = ans;
        }
        
        return memo[i][j];
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends