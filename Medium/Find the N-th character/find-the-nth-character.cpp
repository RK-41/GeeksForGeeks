//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        // 09.03.24 POTD
        
        for(int i=0; i<r; i++){
            string t="";
            int sz = s.size();
            int mn = min(n+1, sz);
            
            for(int j=0; j<mn; j++){
                t += s[j]=='0' ? "01" : "10";
            }
            
            s = t;
        }
        
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends