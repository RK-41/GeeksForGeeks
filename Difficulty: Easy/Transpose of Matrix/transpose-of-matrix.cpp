class Solution {
  public:
    vector<vector<int>> transpose(vector<vector<int>>& mat) {
        // code here
        // 12.12.25 (POTD)
        int n = mat.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                int x = mat[i][j];
                mat[i][j] = mat[j][i];
                mat[j][i] = x;
            }
        }
        
        return mat;
    }
};