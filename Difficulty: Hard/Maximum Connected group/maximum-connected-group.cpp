//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        // code here
        // 11.07.24 potd
        int n = grid.size();
        if(n==0)    return 0;
        
        int maxConnected = 0;
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vector<vector<int>> componentSize(n, vector<int>(n, 0));
        unordered_map<int,int> sizeMap;
        int compId = 2;
        
        function<int(int,int,int)> dfs = [&](int x, int y, int id){
            if(x<0 || y<0 || x>=n || y>=n || vis[x][y] || grid[x][y]==0)
                return 0;
                
            vis[x][y] = true;
            componentSize[x][y] = id;
            int size = 1;
            size += dfs(x+1, y, id);
            size += dfs(x-1, y, id);
            size += dfs(x, y+1, id);
            size += dfs(x, y-1, id);
            
            return size;
        };
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    int size = dfs(i, j, compId);
                    sizeMap[compId] = size;
                    ++compId;
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    unordered_map<int,int> neighborComp;
                    if(i > 0 && grid[i-1][j] == 1)
                        neighborComp[componentSize[i-1][j]]++;
                    
                    if(i < n-1 && grid[i+1][j] == 1)
                        neighborComp[componentSize[i+1][j]]++;
                        
                    if(j > 0 && grid[i][j-1] == 1)
                        neighborComp[componentSize[i][j-1]]++;
                        
                    if(j < n-1 && grid[i][j+1] == 1)
                        neighborComp[componentSize[i][j+1]]++;
                        
                    int potentialSize = 1;
                    for(auto& kv: neighborComp){
                        potentialSize += sizeMap[kv.first];
                    }
                    
                    maxConnected = max(maxConnected, potentialSize);
                }
            }
        }
        
        for(auto& kv: sizeMap){
            maxConnected = max(maxConnected, kv.second);
        }
        
        return maxConnected;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout << obj.MaxConnection(grid) << "\n";
    }
}

// } Driver Code Ends