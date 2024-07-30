//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        // 30.07.24 POTD
        if(mat[0][0] == 0)  return {};
        
        vector<string> ans;
        set<pair<int,int>> vis;
        int n=mat.size();
        traverse(mat, ans, vis, n, 0, 0, "");
        
        return ans;
    }
    
    void traverse(vector<vector<int>>& mat, vector<string>& ans, set<pair<int,int>>& vis, int& n, int i, int j, string path){
        if(i<0 || j<0 || i==n || j==n || vis.count({i,j}) || mat[i][j]==0)
            return;
            
        if(i==n-1 && j==n-1 && mat[i][j]==1){
            ans.push_back(path);
            return;
        }
        
        vis.insert({i,j});
        
        path += 'R';
        traverse(mat, ans, vis, n, i, j+1, path);
        path.pop_back();
        
        path += 'L';
        traverse(mat, ans, vis, n, i, j-1, path);
        path.pop_back();
        
        path += 'U';
        traverse(mat, ans, vis, n, i-1, j, path);
        path.pop_back();
        
        path += 'D';
        traverse(mat, ans, vis, n, i+1, j, path);
        path.pop_back();
        
        vis.erase({i,j});
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends