class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        // 27.06.25 (potd)
        vector<long long int> dp(10);
        vector<vector<int>> adj(10);
        long long ans = 0;
        
        // Numbers that can be generated with one choice
        for(int i=0; i<10; i++){
            dp[i] = 1;
        }
        
        // Possibilities from each number
        adj[0] = {0,8};
        adj[1] = {1,2,4};
        adj[2] = {1,2,3,5};
        adj[3] = {2,3,6};
        adj[4] = {1,4,5,7};
        adj[5] = {2,4,5,6,8};
        adj[6] = {3,5,6,9};
        adj[7] = {4,7,8};
        adj[8] = {0,5,7,8,9};
        adj[9] = {6,8,9};
        
        for(int i=2; i<=n; i++){
            vector<long long int> curr(10,0);
            for(int j=0; j<10; j++){
                for(int prev: adj[j]){
                    curr[j] += dp[prev];
                }
            }
            
            dp = curr;
        }
        
        for(int i=0; i<10; i++){
            ans += dp[i];
        }
        
        return ans;
    }
};
