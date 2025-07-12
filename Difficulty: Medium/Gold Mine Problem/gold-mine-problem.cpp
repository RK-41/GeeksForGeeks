class Solution {
  public:
    int maxGold(vector<vector<int>>& matrix) {
        // code here
        // 12.07.25 (potd)
        int n = matrix.size(), m = matrix[0].size();
        vector<int> gold(m,0);
        int ans=INT_MIN;
        for(int i=m-1;i>=0;i--){
            vector<int> temp(n,0);
            for(int j=0;j<n;j++){
                int g=matrix[j][i];
                if(i+1<m) g+=gold[j];
                if(i+1<m && j-1>=0) g=max(matrix[j][i]+gold[j-1],g);
                if(i+1<m && j+1<n) g=max(matrix[j][i]+gold[j+1],g);
                ans=max(ans,g);
                temp[j]=g;
            }
            gold=temp;
        }
        return ans;
    }
};