//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    // Approach: Floodfill Algorithm
    void dfs(vector<vector<int>> &grid, int i, int j, int n, int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!=1) return;
        
        grid[i][j]=2;
        
        dfs(grid, i-1, j, n, m);
        dfs(grid, i, j-1, n, m);
        dfs(grid, i+1, j, n, m);
        dfs(grid, i, j+1, n, m);
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        // 29.09.23 potd
        
        int n=grid.size(), m=grid[0].size();
        
        // Convert the 1's present in the borders along with their four directional 1's into 2's
        
        for(int i=0; i<n; i++)  
            if(grid[i][0]==1)   dfs(grid, i, 0, n, m);
            
        for(int j=0; j<m; j++)
            if(grid[0][j]==1)   dfs(grid, 0, j, n, m);
            
        for(int i=0; i<n; i++)
            if(grid[i][m-1]==1) dfs(grid, i, m-1, n, m);
            
        for(int j=0; j<m; j++)
            if(grid[n-1][j]==1) dfs(grid, n-1, j, n, m);
            
        // Now, only present 1's are inside the boundary are those which can't be walked off,
        //  which can be counted
        
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++)
                if(grid[i][j]==1)   count++;
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends