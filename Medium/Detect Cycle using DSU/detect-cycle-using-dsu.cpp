//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class UnionFind{
    private:
        vector<int> parent;
        
    public:
        UnionFind(int sz){
            for(int i{}; i<sz; i++){
                parent.push_back(i);
            }
        }
        
        int find(int i){
            if(i == parent[i]) 
                return i;
                
            return parent[i] = find(parent[i]);
        }
        
        void join(int i, int j){
            int parent_i = this->find(i), parent_j = this->find(j);
            int mn = min(parent_i, parent_j), mx = max(parent_i, parent_j);
            
            parent[mn] = mx;
        }
};

class Solution
{
    public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	   // 27.11.23 potd
	   UnionFind uf(V);
	   
	   for(int node{}; node<V; node++){
	       for(int child: adj[node]){
	           if(node < child){
	               if(uf.find(node) == uf.find(child)){
	                   return 1;
	               } else {
	                   uf.join(node, child);
	               }
	           }
	       }
	   }
	   
	   return 0;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		int ans = obj.detectCycle(V, adj);
		cout << ans <<"\n";	}
	return 0;
}
// } Driver Code Ends