class Solution {
  public:
    int subarraySum(vector<int>& arr) {
        // code here
        // 23.07.25 POTD
        int ans = 0, n = arr.size();
        
        for(int i=0; i<n; i++){
            int left = i, right = n-i-1;
            int count = 1;
            if(left > 0){
                count += left;
            }
            if(right > 0){
                count += right;
            }
            if(left > 0 and right > 0){
                count += (left * right);
            }
            
            // cout<<count<<' ';
            ans += count * arr[i];
        }
        
        return ans;
    }
};