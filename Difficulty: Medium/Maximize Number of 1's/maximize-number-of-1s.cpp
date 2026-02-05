class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        // code here
        // 05.02.26 POTD
        int sm = accumulate(arr.begin(), arr.end(), 0);
        int n = arr.size();
        if(n == sm) return n;
        
        // zero count upto index i from left to right
        vector<int> zeros(n);
        int z = 0;
        
        for(int i=0; i<n; i++){
            z += arr[i] == 0 ? 1 : 0;
            zeros[i] = z;
        }
        
        int ans = 0, i=0, j=0;
        while(i<n && j<n){
            int left = i == 0 ? 0 : zeros[i-1];
            int right = zeros[j];
            if(right - left <= k || arr[j] == 1){
                j++;
            } else {
                ans = max(ans, j-i);
                i++;
            }
            
        }
        return max(ans, j-i);
    }
};
