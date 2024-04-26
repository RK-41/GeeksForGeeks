//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mat) {
        // Code here
        // 26.04.24 POTD
        vector<int> ans {0,0};
        char currDir = 'e';
        // e: east
        int i=0, j=0;
        
        while(i>=0 && j>=0 && i<n && j<m){
            ans = {i,j};
            if(mat[i][j] == 0){
                switch(currDir){
                    case 'e':
                        j++;
                        break;
                    case 's':
                        i++;
                        break;
                    case 'w':
                        j--;
                        break;
                    case 'n':
                        i--;
                        break;
                    }
                } else {
                    mat[i][j] = 0;
                    switch(currDir){
                    case 'e':
                        currDir = 's';
                        i++;
                        break;
                    case 's':
                        currDir = 'w';
                        j--;
                        break;
                    case 'w':
                        currDir = 'n';
                        i--;
                        break;
                    case 'n':
                        currDir = 'e';
                        j++;
                        break;
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends