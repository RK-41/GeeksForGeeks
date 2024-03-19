//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
  int ans;
  vector<int> maximumWeight(int n, vector<vector<int>> edges, int q, vector<int> &queries) {
    // code here
	// 19.03.24 potd
    // Approach: Disjoint-Set Union with Path Compression and Cumulative Weighting

    // Vector to store parent of each node (for DSU)
    vector<int> parent(n + 1, 0);
    // Vector to store size of the tree rooted at each node (for path compression)
    vector<int> sz(n + 1, 0);
    // Vector to store edges with {weight, {node1, node2}}
    vector<pair<int, pair<int, int>>> wt;
    // Map to store weight and the maximum weight in the forest after processing edges with that weight
    map<int, int> mp;
    // Vector to store results for each query
    vector<int> res;
    ans = 0;

    // Initialize parent and size vectors (each node is its own parent with size 1)
    for (int i = 0; i < n; i++) {
      parent[i] = i;
      sz[i] = 1;
    }

    // Initialize wt vector with {weight, {node1, node2}}
    for (int i = 0; i < edges.size(); i++) {
      wt.push_back({edges[i][2], {edges[i][0], edges[i][1]}});
    }

    // Sort wt vector in non-decreasing order of weight
    sort(wt.begin(), wt.end());

    // Create a map to store the maximum weight in the forest after processing edges with a specific weight
    for (int i = 0; i < n - 1; i++) {
      int val = wt[i].first; // weight of the current edge
      int node1 = wt[i].second.first;  // node1 of the current edge
      int node2 = wt[i].second.second; // node2 of the current edge

      // Union operation (connect node1 and node2) and update the maximum weight in the forest
      mp[val] = Union(node1, node2, parent, sz);
    }

    // Process each query
    for (int i = 0; i < q; i++) {
      auto it = mp.upper_bound(queries[i]); // first element in mp strictly greater than the query weight

      // If no edge with weight greater than the query weight exists, result is 0
      if (it == mp.begin()) {
        res.push_back(0);
      } else {
        // Decrement the iterator to get the element with the largest weight less than or equal to the query weight
        it--;
        res.push_back(it->second); // maximum weight in the forest after processing edges with weight <= query weight
      }
    }

    return res;
  }

  // Function to find the root of a node (parent with parent pointing to itself)
  int Find(int i, vector<int> &parent) {
    while (parent[i] != i) {
      parent[i] = parent[parent[i]]; // path compression (makes future Find operations faster)
      i = parent[i];
    }
    return i;
  }

  // Union function to connect two nodes (merge trees) and update the maximum weight in the forest
  int Union(int a, int b, vector<int> &p, vector<int> &sz) {
    int ra = Find(a, p); // root of node a
    int rb = Find(b, p); // root of node b

    // If already connected, return the current maximum weight
    if (ra == rb)
      return sz[ra] * sz[rb];

    // Attach the smaller tree to the root of the larger tree (weighted union)
    if (sz[ra] < sz[rb]) {
      swap(ra, rb);
      swap(a, b);
    }

    // Update the cumulative sum of the number of paths with maximum weight as the current weight
    ans += sz[ra] * sz[rb];

    // Make root of 'rb' a child of root of 'ra'
    p[rb] = ra;

    // Update the size of the set
    sz[ra] += sz[rb];
    
    // Return the number of paths
    return ans;
    }
};




//{ Driver Code Starts.

int main() 
{
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
        cin >> n;
        
        vector<vector<int>> edges(n-1, vector<int> (3, 0));

        for(int i = 0; i < n-1; i++)
        {
        	for(int j = 0; j < 3; j++)
        	{
        		cin >> edges[i][j];
        	}
        }

        int q;
        cin >> q;
        vector<int> queries(q);
        for(int i = 0; i < q; i++)
        	cin >> queries[i];

    	Solution obj;
    	vector<int> ans = obj.maximumWeight(n, edges, q, queries);

    	for(auto i:ans)
    		cout << i << " ";
    	cout << "\n"; 
    }
    return 0;
}

// } Driver Code Ends