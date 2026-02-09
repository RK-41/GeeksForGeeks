class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        // 09.02.26 POTD
        int ans = 1, n = arr.size();
        
        while(ans<n){
            if(arr[ans-1] > arr[ans])   break;
            ans++;
        }
        
        return ans%n;
    }
};
