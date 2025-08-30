// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        // 30.08.25 (POTD)
        int n = mat.size();
        vector<int> fanCount(n, 0), celebs;
        
        for(int i=0; i<n; i++){
            int following = 0;
            for(int j=0; j<n; j++){
                
                if(mat[i][j] == 1){
                    following += mat[i][j];
                    fanCount[j]++;
                }
            }
            
            if(following == 1){
                celebs.push_back(i);
            }
        }
        
        for(auto c: celebs){
            if(fanCount[c] == n){
                return c;
            }
        }
        
        return -1;
    }
};
