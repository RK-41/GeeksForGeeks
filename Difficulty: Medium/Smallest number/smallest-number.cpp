//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        // 15.07.24 POTD
        if(s > 9*d)
            return "-1";
            
        string ans;
        int n = pow(10,d-1), p=1, i=0;
        s--;
        
        for(i=0; i<d; i++){
            int dig = min(9, s);
            s -= min(9, s);
            dig *= p;
            n += dig;
            p *= 10;
        }
        
        return s == 0 && i == d ? to_string(n) : "-1";
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends