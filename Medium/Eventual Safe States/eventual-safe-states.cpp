//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        // 18.10.23 potd
        
        vector<int> topo;
        vector<int> vis(V, false);
        
        for(int i=0; i<V; i++){
            if(vis[i] == false)
                dfs(i, vis, topo, adj);
        }
        
        vector<int> res;
        vector<int> mark(V, false);
        
        for(auto it: topo){
            bool flg = true;
            
            for(int nbr: adj[it]){
                if(mark[nbr] == false){
                    flg = false;
                    break;
                }
            }
            
            if(flg){
                mark[it] = true;
                res.push_back(it);
            }
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
    
    void dfs(int node, vector<int> &vis, vector<int> &topo, vector<int> adj[]){
        vis[node] = true;
        
        for(int nbr: adj[node]){
            if(vis[nbr] == false)
                dfs(nbr, vis, topo, adj);
        }
        
        topo.push_back(node);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends