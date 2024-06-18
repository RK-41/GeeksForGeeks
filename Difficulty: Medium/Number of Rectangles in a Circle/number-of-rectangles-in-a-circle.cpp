//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int rectanglesInCircle(int r) {
        // code here
        // 18.06.24 POTD
        if(r == 1)  return 1;
        
        int ans=0, d=r+r;
        
        for(int i=1; i<=d; i++){
            for(int j=1; j<=d; j++){
                double diag = sqrt(i*i + j*j);
                if(diag <= d){
                    ans += 1;
                }
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
        int n;
        cin >> n;
        Solution ob;
        int ans = ob.rectanglesInCircle(n);
        cout << ans << "\n";
    }
}
// } Driver Code Ends