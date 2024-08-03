//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        // 03.08.24 POTD
        int ans = -1, n = mat.size(), count = 0;
        vector<int> fanCount(n, 0), celebs;
        
        for(int i=0; i<n; i++){
            int fans = 0;
            for(int j=0; j<n; j++){
                
                if(mat[i][j] == 1){
                    fans += mat[i][j];
                    fanCount[j]++;
                }
            }
            
            if(fans == 0){
                celebs.push_back(i);
            }
        }
        
        for(auto c: celebs){
            if(fanCount[c] == n-1){
                count++;
                ans = c;
            }
        }
        
        return count == 1 ? ans : -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends