//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        // Your code here
        // 27.08.24 potd
        int ans=0, n=arr.size();
        vector<int> leftSmaller(n), rightSmaller(n);
        stack<int> stk;
        
        for(int i=0; i<n; i++){
            while(stk.size() && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            if(stk.size()){
                leftSmaller[i] = arr[stk.top()];
            }
            stk.push(i);
        }
        
        while(stk.size()){
            stk.pop();
        }
        
        for(int i=n-1; i>=0; i--){
            while(stk.size() && arr[stk.top()]>=arr[i]){
                stk.pop();
            }
            if(stk.size()){
                rightSmaller[i] = arr[stk.top()];
            }
            stk.push(i);
        }
        
        for(int i=0; i<n; i++){
            ans = max(ans, abs(leftSmaller[i] - rightSmaller[i]));
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
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends