//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int> > &matrix) {
        // code here
        // 01.08.24 POTD
        vector<int> ans;
        int n=matrix.size(), m=matrix[0].size(), l=0, r=m-1, t=0, b=n-1;
        
        while(l<=r && t<=b){
            // left to right
            for(int j=l; j<=r; j++){
                ans.push_back(matrix[t][j]);
            }
            t++;
            
            // top to bottom
            for(int i=t; i<=b; i++){
                ans.push_back(matrix[i][r]);
            }
            r--;
            
            // right to left
            if(t<=b){
                for(int j=r; j>=l; j--){
                    ans.push_back(matrix[b][j]);
                }
                b--;
            }
            
            // bottom to top
            if(l<=r){
                for(int i=b; i>=t; i--){
                    ans.push_back(matrix[i][l]);
                }
                l++;
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
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends