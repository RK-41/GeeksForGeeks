//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int largestSubsquare(int n, vector<vector<char>> a) {
        // code here
        // 14.03.24 potd
        int ans=0;
        vector<vector<int>> vert(n, vector<int>(n,0));  // vertical
        vector<vector<int>> horiz(n, vector<int>(n,0)); // horizontal
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(a[i][j]=='X'){
                    vert[i][j] = i==0 ? 1: vert[i-1][j]+1;
                    horiz[i][j] = j==0 ? 1: horiz[i][j-1]+1;
                }
            }
        }
        
        for(int i=n-1; i>=0; i--){
            for(int j=n-1; j>=0; j--){
                int val=min(vert[i][j], horiz[i][j]);
                
                while(val>ans){
                    if(vert[i][j-val+1]>=val and horiz[i-val+1][j]>=val){
                        ans = val;
                    }
                    
                    val--;
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
        vector<vector<char>> a(n, vector<char>(n));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> a[i][j];
        }
        Solution ob;
        cout << ob.largestSubsquare(n, a) << "\n";
    }
}
// } Driver Code Ends