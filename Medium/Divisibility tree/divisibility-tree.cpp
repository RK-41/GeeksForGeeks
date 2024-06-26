//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution {
public:
	int minimumEdgeRemove(int n, vector<vector<int>>edges){
	    // Code here
        // 16.05.24 potd
        
        int total = 0;
        unordered_map<int,vector<int>> adj;
        
        for(auto e: edges){
            int u = e[0], v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        solve(adj, total, 1);
        
        return total;
	}
	
	int solve(unordered_map<int,vector<int>> &adj, int &total, int curr, int prev=-1){
	    int ans = 0;
	    for(auto v: adj[curr]){
	        if(v != prev){
	            int res = solve(adj, total, v, curr);
	            if(res%2 == 0){
	                total++;
	            } else {
	                ans += res;
	            }
	        }
	    }
	    
	    return ans+1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>edges;
		for(int i = 0; i < n-1; i++){
			int x, y;
			cin >> x >> y;
			edges.push_back({x,y});
		}
		Solution obj;
		int ans = obj.minimumEdgeRemove(n, edges);
		cout << ans <<"\n";
	}
	return 0;
}

// } Driver Code Ends