//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        // 19.09.24 POTD
        string ans, word;
        
        for(auto c: str){
            if(c == '.'){
                ans = ans.size() ? word + "." + ans : word;
                word = "";
            } else {
                word += c;
            }
        }
        ans = ans.size() ? word + "." + ans : word;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends