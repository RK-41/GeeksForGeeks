#define vvb vector<vector<bool>>
#define vvc vector<vector<char>>
class Solution {
  public:
    int d[5] = {0, 1, 0, -1, 0};    // Direction 'vector'
    bool isWordExist(vvc& mat, string& word) {
        // 06.02.25
        // 27.01.26 (POTD)
        int n = mat.size(), m = mat[0].size();
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                // When current char matches with first char of given word
                if(mat[i][j] == word[0]){
                    // A m*n boolean vector to store visit status of chars
                    vvb vis(n, vector<bool>(m, false));
                    
                    // Checking if given word can be formed
                    if(check(mat, i, j, 0, word, vis))
                        return true;
                }
            }
        }
        
        return false;   // When given word can't be formed
    }
    
private:
    bool check(vvc& mat, int i, int j, int idx, string& word, vvb& vis){
        if(idx == word.size())  // Meaning all the chars matched with word
            return true;

        // Out of bound, already visited or doesn't match with current word char
        if(i<0 || j<0 || i>=mat.size() || j>=mat[0].size() 
            || vis[i][j] || mat[i][j] != word[idx])
            return false;
            
        vis[i][j] = true;   // Setting visit status
        
        for(int x=0; x<4; x++){ // Checking in all four directions
            if(check(mat, i+d[x], j+d[x+1], idx+1, word, vis))
                return true;
        }
        
        vis[i][j] = false;  // Resetting visit status
        return false;   // This path doesn't form the word
    }
};
