//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        // Code Here
        // 15.11.24 POTD
        int ans=0, a=0, n=arr.size();
        
        for(int i=0; i<n; i++){
            if(a < arr[i]){
                ans = a;
                a = arr[i];
            } else if(ans < arr[i] && arr[i] < a){
                ans = arr[i];
            }
        }
        
        return ans > 0 ? ans : -1;
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
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends