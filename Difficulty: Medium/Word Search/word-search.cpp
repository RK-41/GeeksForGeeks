//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int d[5] = {0, 1, 0, -1, 0};
    bool isWordExist(vector<vector<char>>& mat, string& word) {
        // Code here
        // 01.02.25 POtD
        int n = mat.size(), m = mat[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j] == word[0]){
                    vector<vector<bool>> vis(n, vector<bool>(m, false));
                    if(check(mat, i, j, 0, word, vis))
                        return true;
                }
            }
        }
        
        return false;
    }
    
private:
    bool check(vector<vector<char>>& mat, int i, int j, int idx, string& word, vector<vector<bool>>& vis){
        if(idx == word.size())
            return true;

        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() || vis[i][j] || mat[i][j] != word[idx])
            return false;
            
        vis[i][j] = true;
        
        for(int x=0; x<4; x++){
            bool res = check(mat, i+d[x], j+d[x+1], idx+1, word, vis);
            if(res) return true;
        }
        
        vis[i][j] = false;
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends