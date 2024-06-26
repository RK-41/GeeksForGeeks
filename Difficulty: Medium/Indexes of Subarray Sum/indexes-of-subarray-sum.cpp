//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int> arr, int n, long long s) {
        // Your code here
        // 01.07.24 potd
        long long int sum = arr[0];
        int r = 0, l = 0;
        
        while(r < n){
            if(sum == s){
                return {l+1, r+1};
            } else if(sum < s){
                r++;
                sum += arr[r];
            } else if(sum > s && l == r){
                l++, r++;
                sum = arr[l];
            } else {
                sum -= arr[l];
                l++;
            }
        }
        
        
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long s;
        cin >> n >> s;
        vector<int> arr(n);
        // int arr[n];
        const int mx = 1e9;
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        vector<int> res;
        res = ob.subarraySum(arr, n, s);

        for (int i = 0; i < res.size(); i++)
            cout << res[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends