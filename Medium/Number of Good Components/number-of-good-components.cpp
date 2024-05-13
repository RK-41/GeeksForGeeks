//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findNumberOfGoodComponent(int e, int v, vector<vector<int>> &edges) {
        // code here
        // 13.05.24 potd
        int ans=0;
        vector<int> adj[v+2];
        vector<bool> vis(v+2,0);
        
        for(auto e: edges){
            int u=e[0];
            int v=e[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        
        for(int i=1; i<=v; i++){
            if(!vis[i]){
                unordered_set<int> st;
                dfs(i, adj, vis, st);
                
                bool flag = true;
                
                for(int n: st){
                    if(adj[n].size() != st.size()-1){
                        flag = false;
                        break;
                    }
                }
                
                if(flag){
                    ans++;
                }
            }
        }
        
        return ans;
    }
    
    void dfs(int i, vector<int> adj[], vector<bool> &vis, unordered_set<int> &st){
        vis[i]=true;
        st.insert(i);
        
        for(int n: adj[i]){
            if(!vis[n]){
                dfs(n, adj, vis, st);
            }
        }
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        int res = obj.findNumberOfGoodComponent(e, v, edges);

        cout << res << endl;
    }
}

// } Driver Code Ends