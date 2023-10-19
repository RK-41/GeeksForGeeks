//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    // code here
	    // 19.10.23 POTD
	    // APPROACH: BFS
	    
	    if(X==0)    return 0;
	    
	    int level = 1;
	    queue<int> q;
	    vector<int> vis(V, 0);
	    
	    q.push(0);
	    vis[0] = 1;
	    
	    while(q.size()){
	        int sz = q.size();
	        
	        while(sz--){
	            auto nd = q.front();
	            q.pop();
	            
	            for(auto n: adj[nd]){
    	            if(n == X) return level;
    	            
    	            if(!vis[n])
        	            q.push(n);
        	            
        	        vis[n] = 1;
	            }
	        }
	        level++;
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends