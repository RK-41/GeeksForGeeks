class Solution {
  public:
    void swapDiagonal(vector<vector<int>> &mat) {
        // code here
        // 13.12.25 POTD
        int n = mat.size();
        
        for(int i=0; i<n/2; i++){
            int x = mat[i][i];
            mat[i][i] = mat[i][n-1-i];
            mat[i][n-1-i] = x;
            
            x = mat[n-1-i][i];
            mat[n-1-i][i] = mat[n-1-i][n-1-i];
            mat[n-1-i][n-1-i] = x;
        }
    }
};
