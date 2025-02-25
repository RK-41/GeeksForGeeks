//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int getMaxArea(vector<int> &arr) {
        // Your code here
        // 25.02.25 (POTD)
        
        stack<int> stk;
        int ans = 0, n = arr.size();
        
        for(int i=0; i<n; i++){
            // pop while arr[TOS] is >= arr[i] -> finding previsous smaller ele
            while(stk.size() && arr[i]<=arr[stk.top()]){
                int tos = stk.top();
                stk.pop();
                
                int curr = arr[tos] * (stk.empty()? i : (i - stk.top() - 1));
                
                ans = max(ans, curr);
            }
            stk.push(i);
        }
        
        // Stack now stores elements which don't've next smaller element
        while(stk.size()){
            int tos = stk.top();
            stk.pop();
            
            int curr = arr[tos] * (stk.empty()? n: (n - stk.top() -1));
            
            ans = max(ans,curr);
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.getMaxArea(arr);
        cout << res << endl;
        cout << "~" << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends