//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int n, int arr[])
    {
        // code here
        // 15.09.23 Potd
        
        // Step 1: Calculating total sum of array elements
        int totalSum = 0;
        
        for(int i=0; i<n; i++){
            totalSum += arr[i];
        }
        
        // Step 2: Checking if totalSum is odd.
        // Odd sum can't be properly divided into two equal parts as integers.
        if(totalSum%2==1)   return false;
        
        // Step 3: Initializing a dp vector of size 'totalSum+1'.
        vector<int> dp(totalSum+1);
        
        // A sum of 0 can be achieved using an empty sub-array.
        dp[0] = 1;
        
        // Step 4: DP Loop
        // Iterating through the array. For each array, traversing 'dp' in reverse
        // order from 'totalSum/2' down to 'arr[i-1]'.
        // 'dp[j]' is updated if it's possible to achieve a sum of 'j' using
        // the current element 'arr[i-1]'.
        
        for(int i=1; i<=n; i++){
            for(int j=totalSum/2; j>=arr[i-1]; j--){
                
                // if arr[i-1] <= j, it can either be considered or skipped
                if(arr[i-1] <= j){
                    
                    // dp[j] is updated to true if either:
                    //  1. dp[j] is already true
                    //  2. sum 'j-arr[i-1]' can be formed with previous elements
                    dp[j] = dp[j] || dp[j - arr[i-1]];
                }
            }
        }
        
        // Step 5: Returning the result
        // If dp[totalSum/2] is true, it means that the array can be partitioned into 
        // two equal sums.
        // Otherwise, it's not possible.
        return dp[totalSum/2];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends