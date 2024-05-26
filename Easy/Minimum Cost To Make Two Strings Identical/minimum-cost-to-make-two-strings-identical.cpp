//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findMinCost(string x, string y, int costX, int costY) {
        // Your code goes here
        // 26.05.24 potd
        int n=x.size(), m=y.size();
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        for(int j=0; j<=m; j++){
            prev[j] = (m-j)*costY;
        }
        
        for(int i=n-1; i>=0; i--){
            curr[m] = (n-i)*costX;
            
            for(int j=m-1; j>=0; j--){
                if(x[i] == y[j]){
                    curr[j] = prev[j+1];   
                } else {
                    int delX = costX + prev[j];
                    int delY = costY + curr[j+1];
                    curr[j] = min(delX, delY);
                }
            }
            
            prev = curr;
        }
        
        return prev[0];
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;

        int costX, costY;
        cin >> costX >> costY;

        Solution ob;
        cout << ob.findMinCost(x, y, costX, costY);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends