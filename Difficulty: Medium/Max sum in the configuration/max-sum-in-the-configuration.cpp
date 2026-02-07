class Solution {
  public:
    int maxSum(vector<int> &arr) {
        // code here
        // 07.02.26 potd
        int ans = 0, sm = 0, curr = 0, n = arr.size();
        
        for(int i=0; i<n; i++){
            sm += arr[i];
            curr += arr[i] * i;
        }
        
        ans = curr;
        for(int i=1; i<n; i++){
            curr = curr + sm - n * arr[n-i];
            ans = max(ans, curr);
        }
        
        return ans;
    }
};