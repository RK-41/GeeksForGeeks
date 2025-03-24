//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        // 24.03.25 (potd)
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return memoize(1, n-1, arr, dp);
        
    }
     // MEMOIZATION
    int memoize(int i, int j, vector<int>& arr, vector<vector<int>> & dp){
        if(i==j)    return 0;
        
        if(dp[i][j]!=-1)    return dp[i][j];
        
        int mn=INT_MAX;
        
        for(int k=i; k<j; k++){
            int step=(arr[i-1]*arr[k]*arr[j])+memoize(i,k,arr,dp)+memoize(k+1,j,arr,dp);
            mn=min(mn,step);
        }
        
        return dp[i][j]=mn;
    }

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends