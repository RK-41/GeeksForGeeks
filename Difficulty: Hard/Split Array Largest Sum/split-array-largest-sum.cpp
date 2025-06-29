class Solution {
  public:
    int splitArray(vector<int>& arr, int k) {
        // code here
        // 29.06.25 (potd)
        int N = arr.size();
        int start=0, end=accumulate(arr.begin(), arr.end(), 0);
        int ans;
        
        while(start<=end){
            int mid = (start+end)>>1;
            if(isPossible(arr, k, N, mid)){
                ans=mid;
                end=mid-1;
            } else {
                start=mid+1;
            }
        }
        
        return ans;
    }
    
    bool isPossible(vector<int> arr, int k, int n, int minSol){
        int subSum=0, cnt=1;
        
        for(int i=0; i<n; i++){
            if(arr[i] > minSol){
                return false;
            }
                
            if(arr[i] + subSum > minSol){
                cnt++;
                subSum = arr[i];
                if(cnt > k){
                    return false;
                }
            } else {
                subSum += arr[i];
            }
        }
        
        return true;
    }
};