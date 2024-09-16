//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        // code here
        // 16.09.24 Potd
        int open=0, close=0, ans=0, n=str.size();

        for(int i=0; i<n; i++){
            if(str[i] == '(')   open++;
            else                close++;
            
            if(close > open){
                open = close = 0;
            } else if(open == close){
                ans = max(ans, close*2);
            }
        }
        
        open = close = 0;
        for(int i=n-1; i>=0; i--){
            if(str[i] == '(')   open++;
            else                close++;
            
            if(open > close){
                open = close = 0;
            } else if(open == close){
                ans = max(ans, close*2);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends