//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // code here
        // 23.04.24 potd
        if(n==1) return 1;
        
        int a=0, b=1, c, i;
        int m = 1e9+7;
        
        for(i=2; i<=n; i++){
            c = a+b;
            a = b%m;
            b = c%m;
        }
        
        return b;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends