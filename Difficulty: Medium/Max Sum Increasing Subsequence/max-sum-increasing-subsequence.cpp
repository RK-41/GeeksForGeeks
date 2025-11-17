class Solution {
  public:
    int maxSumIS(vector<int>& arr) {
        // code here
        // 17.11.25 (potd)
        int n = arr.size();
        vector<int> dp(n,INT_MIN);
	    dp[0]=arr[0];
	    
	    for(int i=1; i<n; i++){
	        for(int j=0; j<i; j++)
	            if(arr[j] < arr[i])
	                dp[i]=max(dp[i],arr[i]+dp[j]);
	                
	        dp[i]=max(dp[i],arr[i]);
	    }
	    
	    return *max_element(dp.begin(),dp.end());
    }
};