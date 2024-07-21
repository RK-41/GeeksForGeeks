//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        // 21.07.24 POtd
        if(arr.size() == 1)
            return arr[0];
            
        if(arr.size() == 2){
            return max({arr[0], arr[1], arr[0]*arr[1]});
        }
        
        long long int ans=1;
        int n = arr.size(), MOD=1e9+7, zero=0;
        vector<int> negatives;
        
        for(int i=0; i<n; i++){
            if(arr[i] > 0){
                ans = (ans*arr[i])%MOD;
            } else if(arr[i] < 0){
                negatives.push_back(arr[i]);
            } else {
                zero++;
            }
        }
        
        sort(negatives.begin(), negatives.end());
        int sz = negatives.size();
        
        sz = sz%2 == 1 ? sz-1 : sz;
        
        for(int i=0; i<sz; i++){
            ans = (ans * negatives[i])%MOD;
        }
        
        
        return zero == n ? 0 : ans%MOD;

    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends