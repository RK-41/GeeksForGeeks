//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string binaryNextNumber(string s) {
        // code here.
        // 04.06.24 POTD
        char carry = '1';
        int i, n=s.size();
        
        for(i=0; i<n; i++){
            if(s[i] == '1'){
                s = s.substr(i);
                break;
            }
        }
        
        if(i==n){
            return "1";
        }
        
        for(i=s.size()-1; i>=0; i--){
            if(carry == '1'){
                carry = s[i];
                s[i] = s[i] == '0' ? '1' : '0';
            } else {
                break;
            }
        }
        
        if(carry == '1'){
            s = "1" + s;
        }
        
        return s;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.binaryNextNumber(s);
        cout << "\n";
    }

    return 0;
}
// } Driver Code Ends