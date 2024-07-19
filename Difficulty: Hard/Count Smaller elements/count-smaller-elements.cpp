//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
//  User function template for C++ 

class Solution {
  public:
    vector<int> constructLowerArray(vector<int> &arr) {
        // code here
        // 19.07.24 potd
        vector<int> ans, brr = arr;
        int n = arr.size();
        
        sort(brr.begin(), brr.end());
        
        for(int i=0; i<n; i++){
            // Using binary search for finding the index of arr[i] in brr
            int idx = lower_bound(brr.begin(), brr.end(), arr[i]) - brr.begin();
            ans.push_back(idx);
            
            // Removing the element so that the right side for any ith element doesn't exixt
            brr.erase(brr.begin() + idx);
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
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        vector<int> a = ob.constructLowerArray(arr);
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends