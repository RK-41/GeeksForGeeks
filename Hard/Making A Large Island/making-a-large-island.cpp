//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
public:
    int rdir[4] = {-1,0,1,0};
    int cdir[4] = {0,-1,0,1};
    pair<int,int> parent[501][501];
    int _size[501][501];
    
    int countIsland(vector<vector<int>> &grid, int x, int y, int n, int par_i, int par_j){
        grid[x][y] = 2;
        parent[x][y].first = par_i, parent[x][y].second = par_j;
        
        int t = 1;
        
        for(int i=0; i<4; i++){
            int u = x + rdir[i], v = y + cdir[i];
            
            if(u>=0 and v>=0 and u<n and v<n and grid[u][v]==1){
                t += countIsland(grid, u, v, n, par_i, par_j);
            }
        }
        
        return t;
    }
    int largestIsland(vector<vector<int>>& grid) 
    {
        // Your code goes here.
        // 16.10.12 potd
        // Approach: DFS & Union-Find
        
        int n = (int)grid.size(), ans = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; ++j){
                if(grid[i][j]==1){
                    _size[i][j] = countIsland(grid,i,j,n,i,j);
                    ans = max(ans, _size[i][j]);
                }
            }
        }
        
        for(int i=0; i<n; ++i){
            for(int j=0; j<n; j++){
                if(grid[i][j]==0){
                    int t = 1;
                    set<pair<int,int>> st;
                    
                    for(int k=0; k<4; k++){
                        int u = i+rdir[k], v = j+cdir[k];
                        
                        if(u>=0 and u<n and v>=0 and v<n and grid[u][v]){
                            int p1 = parent[u][v].first, p2 = parent[u][v].second;
                            
                            if(st.find({p1,p2}) == st.end()){
                                t += _size[p1][p2], st.insert({p1,p2});
                            }
                        }
                        
                        ans = max(ans, t);
                    }
                }
            }
    
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin >> t;
    while(t--){

        int n;
        cin>>n;
        vector<vector<int>>grid(n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>grid[i][j];
        Solution ob;
        cout<<ob.largestIsland(grid)<<endl;
    }
    return 0;
}

// } Driver Code Ends