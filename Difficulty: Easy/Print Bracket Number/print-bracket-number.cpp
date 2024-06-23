//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:

    vector<int> bracketNumbers(string str) {
        // Your code goes here
        // 23.06.24 POTD
        vector<int> ans;
        stack<int> stk;
        int open=0, close=0, n=str.size();
        
        for(int i=0; i<n; i++){
            if(str[i] == '('){
                open++;
                stk.push(open);
                ans.push_back(open);
            } else if(str[i] == ')'){
                ans.push_back(stk.top());
                stk.pop();
            }
        }
            
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;

        vector<int> ans = ob.bracketNumbers(s);

        for (auto i : ans)
            cout << i << " ";

        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends