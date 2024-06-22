//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {
        // code here
        // 22.06.24 POTD
        long long ans=-1, mx=0;
        int n = sentence.size();
        bool flg = 0;
        
        for(int i=0; i<n; i++){
            char c = sentence[i];
            
            if(c >= '0' && c <= '9'){
                if(c == '9'){
                    flg = 1;
                    continue;
                }

                mx = mx*10 + c - '0';
            } else {
                if(!flg)
                    ans = max(ans, mx);
                mx = 0;
                flg = 0;
            }
        }
        
        if(!flg)
            ans = max(ans, mx);
        
        return ans > 0 ? ans : -1;
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
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends