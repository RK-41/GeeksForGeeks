class Solution {
  public:
    int minCandy(vector<int> &ratings) {
        // code here
        // 15.01.26 (potd)
        int N = ratings.size();
        vector<int> candy(N,1);
        
        for(int i=1; i<N; i++){
            if(ratings[i] > ratings[i-1]){
                candy[i] = candy[i-1]+1;
            }
        }
        
        for(int i=N-2; i>=0; i--){
            if(ratings[i] > ratings[i+1]){
                candy[i] = max(candy[i+1]+1, candy[i]);
            }
        }
        
        int count = accumulate(candy.begin(), candy.end(), 0);
        return count;
    }
};