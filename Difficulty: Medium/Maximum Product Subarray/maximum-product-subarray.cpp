//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    // Function to find maximum product subarray
    int maxProduct(vector<int> &arr) {
        // Your Code Here
        // 25.11.24 potd
        if(arr.size() == 1) return arr[0];
        int ans=arr[0], n=arr.size(), left=1, right=1;
        
        for(int i=0; i<n; i++){
            if(left == 0)   left = 1;
            if(right == 0)  right = 1;
            
            left *= arr[i];
            right *= arr[n-1-i];
            
            ans = max(ans, max(left,right));
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // int n, i;
        // cin >> n;
        // vector<int> arr(n);
        // for (i = 0; i < n; i++) {
        //     cin >> arr[i];
        // }

        vector<int> arr;
        string input;

        // Read array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        auto ans = ob.maxProduct(arr);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends